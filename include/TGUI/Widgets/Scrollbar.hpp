/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2024 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TGUI_SCROLLBAR_HPP
#define TGUI_SCROLLBAR_HPP

#include <TGUI/Widget.hpp>
#include <TGUI/Renderers/ScrollbarRenderer.hpp>

#if !TGUI_EXPERIMENTAL_USE_STD_MODULE
    #include <chrono>
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TGUI_MODULE_EXPORT namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Scrollbar widget
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Scrollbar : public Widget
    {
    public:

        using Ptr = std::shared_ptr<Scrollbar>; //!< Shared widget pointer
        using ConstPtr = std::shared_ptr<const Scrollbar>; //!< Shared constant widget pointer

        static constexpr const char StaticWidgetType[] = "Scrollbar"; //!< Type name of the widget


        /// @brief Defines when the scrollbar shows up
        enum class Policy
        {
            Automatic,  //!< Show the scrollbar only when needed (default)
            Always,     //!< Always show the scrollbar, even when the contents fits
            Never       //!< Never show the scrollbar, even if the contents does not fit
        };

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Constructor
        /// @param typeName     Type of the widget
        /// @param initRenderer Should the renderer be initialized? Should be true unless a derived class initializes it.
        /// @see create
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar(const char* typeName = StaticWidgetType, bool initRenderer = true);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new scrollbar widget
        ///
        /// @return The new scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD static Scrollbar::Ptr create();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another scrollbar
        ///
        /// @param scrollbar  The other scrollbar
        ///
        /// @return The new scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD static Scrollbar::Ptr copy(const Scrollbar::ConstPtr& scrollbar);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer that may be shared with other widgets using the same renderer
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD ScrollbarRenderer* getSharedRenderer() override;
        TGUI_NODISCARD const ScrollbarRenderer* getSharedRenderer() const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer
        /// @warning After calling this function, the widget has its own copy of the renderer and it will no longer be shared.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD ScrollbarRenderer* getRenderer() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the scrollbar
        ///
        /// @param size  The new size of the scrollbar
        ///
        /// Note that the VerticalScroll propery is changed by this function based on the given width and height.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Widget::setSize;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets a maximum value
        /// @param maximum  The new maximum value
        ///
        /// When the value is bigger than (maximum - viewportSize), the value is set to maximum - viewportSize.
        /// The default maximum value is 10.
        /// @see setViewportSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximum(unsigned int maximum);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum value
        ///
        /// @return The current maximum value
        ///
        /// The default maximum value is 10.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getMaximum() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the current value
        /// @param value  The new value
        ///
        /// The value has to be smaller than maximum - viewportSize.
        /// @see setViewportSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setValue(unsigned int value);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the current value
        ///
        /// @return The current value
        ///
        /// The default value is 0.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getValue() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the viewport size
        ///
        /// @param viewport  The new viewport size
        ///
        /// If the contents through which the scrollbar can scroll is 600 pixels of which only 200 pixels are visible on the
        /// screen then the viewport size should be set to 200 and the maximum should be set to 600. The thumb will occupy
        /// one third of the scrollbar track in this case. The possible scrollbar values are in the range [0, 400] in this case.
        ///
        /// Until the maximum is bigger than this value, no scrollbar will be drawn.
        /// You can however choose to always draw the scrollbar by calling setAutoHide(false).
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setViewportSize(unsigned int viewport);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the viewport size
        /// @see setViewportSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getViewportSize() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum value that can be set with the setValue function
        ///
        /// @return getMaximum() - getViewportSize() if getMaximum() >= getViewportSize(), otherwise 0
        ///
        /// @since TGUI 1.4
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getMaxValue() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes how much the value changes when scrolling or pressing one of the arrows of the scrollbar
        ///
        /// @param scrollAmount  How far should the scrollbar scroll when an arrow is clicked?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScrollAmount(unsigned int scrollAmount);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns how much the value changes when scrolling or pressing one of the arrows of the scrollbar
        ///
        /// @return How far should the scrollbar scroll when an arrow is clicked?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getScrollAmount() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the scrollbar should hide automatically or not
        /// @param autoHide  Should the scrollbar be invisible when you can't scroll?
        ///
        /// When true (default), the scrollbar will not be drawn when the maximum is smaller than the viewportSize.
        /// @see setViewportSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setAutoHide(bool autoHide);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the scrollbar is hiding automatically or not
        ///
        /// When true (default), the scrollbar will not be drawn when the maximum is smaller than the viewportSize.
        /// @see setViewportSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool getAutoHide() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the scrollbar lies horizontally or vertically
        /// @param vertical  Should the scrollbar lie vertically?
        ///
        /// This function will swap the width and height of the scrollbar if it didn't lie in the wanted direction.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVerticalScroll(bool vertical);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the scrollbar lies horizontally or vertically
        /// @return Does the scrollbar lie vertically?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool getVerticalScroll() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the default width of the scrollbar
        /// @return Default scrollbar width
        ///
        /// The default width is the value the scrollbar has on construction or the size of the texture once a texture is set.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD float getDefaultWidth() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the mouse position (which is relative to the parent widget) lies on top of the widget
        ///
        /// @return Is the mouse on top of the widget?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool isMouseOnWidget(Vector2f pos) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool leftMousePressed(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMouseReleased(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseMoved(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool scrolled(float delta, Vector2f pos, bool touch) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMouseButtonNoLongerDown() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draw the widget to a render target
        ///
        /// @param target Render target to draw to
        /// @param states Current render states
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(BackendRenderTarget& target, RenderStates states) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Updates the scrollbar after a size change
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateSize();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves a signal based on its name
        ///
        /// @param signalName  Name of the signal
        ///
        /// @return Signal that corresponds to the name
        ///
        /// @throw Exception when the name does not match any signal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Signal& getSignal(String signalName) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Name of the property that was changed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rendererChanged(const String& property) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Saves the widget as a tree node in order to save it to a file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD std::unique_ptr<DataIO::Node> save(SavingRenderersMap& renderers) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the widget from a tree of nodes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void load(const std::unique_ptr<DataIO::Node>& node, const LoadingRenderersMap& renderers) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Updates the position of the thumb based on the current value of the slider
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateThumbPosition();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Widget::Ptr clone() const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        SignalUInt onValueChange = {"ValueChanged"}; //!< Value of the scrollbar changed. Optional parameter: new value

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        enum class Part
        {
            Track,
            Thumb,
            ArrowUp,
            ArrowDown
        };

        // Keep track on which part of the scrollbar the mouse is standing
        Part m_mouseHoverOverPart = Part::Thumb;

        // When the mouse went down, did it go down on top of the thumb? If so, where?
        bool m_mouseDownOnThumb = false;
        Vector2f m_mouseDownOnThumbPos;

        unsigned int m_maximum = 10;
        unsigned int m_value = 0;

        // Maximum should be above this value before the scrollbar is needed
        unsigned int m_viewportSize = 1;

        // Is the scrollbar draw vertically?
        bool m_verticalScroll = true;

        // Does the image lie vertically?
        bool m_verticalImage = true;

        // How far should the value change when pressing one of the arrows?
        unsigned int m_scrollAmount = 1;

        // When no scrollbar is needed, should the scrollbar be drawn or stay hidden?
        bool m_autoHide = true;

        // Did the mouse went down on one of the arrows?
        bool m_mouseDownOnArrow = false;

        bool m_sizeSet = false; // Has setSize been called?

        std::chrono::steady_clock::time_point m_lastSuccessfulScrollTime; // Timestamp of the last mouse wheel scroll event
        Vector2f m_lastSuccessfulScrollPos; // Mouse position at the last mouse wheel scroll event

        FloatRect m_track;
        FloatRect m_thumb;
        FloatRect m_arrowUp;
        FloatRect m_arrowDown;

        Sprite m_spriteTrack;
        Sprite m_spriteTrackHover;
        Sprite m_spriteThumb;
        Sprite m_spriteThumbHover;
        Sprite m_spriteArrowUp;
        Sprite m_spriteArrowUpHover;
        Sprite m_spriteArrowDown;
        Sprite m_spriteArrowDownHover;

        // Cached renderer properties
        Color m_thumbColorCached;
        Color m_thumbColorHoverCached;
        Color m_trackColorCached;
        Color m_trackColorHoverCached;
        Color m_arrowColorCached;
        Color m_arrowColorHoverCached;
        Color m_arrowBackgroundColorCached;
        Color m_arrowBackgroundColorHoverCached;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Wrapper around scrollbar to be used inside widgets that need a scrollbar
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ScrollbarChildWidget : public Scrollbar
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the left mouse button has been pressed on top of the thumb of the scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool isMouseDownOnThumb() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the scrollbar is currently visible
        /// @return Is the scrollbar visible?
        ///
        /// The scrollbar is visible when auto hide is disabled or when the maximum is higher than the viewport size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool isShown() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draw the widget to a render target
        ///
        /// @param target Render target to draw to
        /// @param states Current render states
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(BackendRenderTarget& target, RenderStates states) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SCROLLBAR_HPP
