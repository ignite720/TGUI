/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2016 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_LABEL_HPP
#define TGUI_LABEL_HPP


#include <TGUI/Widgets/ClickableWidget.hpp>
#include <TGUI/Renderers/LabelRenderer.hpp>
#include <TGUI/Text.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Label widget
    ///
    /// Signals:
    ///     - DoubleClicked (double left clicked on top of the label)
    ///         * Optional parameter sf::String: text of the label
    ///         * Uses Callback member 'text'
    ///
    ///     - Inherited signals from ClickableWidget
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Label : public ClickableWidget
    {
    public:

        typedef std::shared_ptr<Label> Ptr; ///< Shared widget pointer
        typedef std::shared_ptr<const Label> ConstPtr; ///< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief The horizontal text alignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class HorizontalAlignment
        {
            Left,   ///< Put the text on the left side (default)
            Center, ///< Center the text horizontally
            Right   ///< Put the text on the right side (e.g. for numbers)
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief The vertical text alignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class VerticalAlignment
        {
            Top ,   ///< Put the text at the top (default)
            Center, ///< Center the text vertically
            Bottom  ///< Put the text at the bottom
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Label();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another label
        ///
        /// @param label  The other label
        ///
        /// @return The new label
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static Label::Ptr copy(Label::ConstPtr label);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        ///
        /// @return Temporary pointer to the renderer
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        LabelRenderer* getRenderer() const
        {
            return aurora::downcast<LabelRenderer*>(m_renderer.get());
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the area of the text that will be drawn
        ///
        /// @param size  Size of the part to draw
        ///
        /// Only the part of the text that lies within the size will be drawn.
        ///
        /// When a background color is set, the drawn background will have this size.
        /// So setting a size that is bigger than the text will result in a bigger area being filled.
        ///
        /// When this function is called, the label will no longer be auto-sizing.
        ///
        /// @see setAutoSize
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(const Layout2d& size) override;
        using Transformable::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text
        ///
        /// @param text  The new text
        ///
        /// When the text is auto-sized (default), then the size of the label will be changed to fit the whole text.
        ///
        /// @see setAutoSize
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setText(const sf::String& text);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text
        ///
        /// @return Text that is currently used
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::String& getText() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the character size of the text
        ///
        /// @param size  The new text size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextSize(unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the character size of the text
        ///
        /// @return The current text size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTextSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the horizontal text alignment
        ///
        /// @param alignment  The new horizontal text alignment
        ///
        /// By default the text is aligned to the left.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setHorizontalAlignment(HorizontalAlignment alignment);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Gets the current horizontal text alignment
        ///
        /// @return Horizontal text alignment
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        HorizontalAlignment getHorizontalAlignment() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the vertical text alignment
        ///
        /// @param alignment  The new vertical text alignment
        ///
        /// By default the text is aligned to the top.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVerticalAlignment(VerticalAlignment alignment);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Gets the current vertical text alignment
        ///
        /// @return Vertical text alignment
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        VerticalAlignment getVerticalAlignment() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the label is auto-sized or not
        ///
        /// @param autoSize  Should the size of the label be changed when the text changes?
        ///
        /// When the label is in auto-size mode, the width and height of the label will be changed to fit the text.
        /// Otherwise, only the part defined by the size will be visible.
        ///
        /// The label is auto-sized by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setAutoSize(bool autoSize);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the label is auto-sized or not
        ///
        /// @return Is the size of the label changed when the text changes?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool getAutoSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the maximum width that the text will have when auto-sizing
        ///
        /// @param maximumWidth The new maximum text width
        ///
        /// This property is ignored when an exact size has been given.
        /// Pass 0 to this function to disable the maximum.
        ///
        /// When the text is auto-sizing then the text will be split over several lines when its width would exceed the
        /// value passed to this function.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximumTextWidth(float maximumWidth);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum width that the text will have
        ///
        /// @return
        ///        - The width of the label minus the padding when a specific size was set.
        ///        - The maximum text width when auto-sizing and a maximum was set.
        ///        - 0 when auto-sizing but there is no maximum width.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getMaximumTextWidth() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// This function is called when the widget is added to a container.
        /// You should not call this function yourself.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setParent(Container* parent) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void leftMouseReleased(float x, float y) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Lowercase name of the property that was changed
        /// @param value     New value of the property
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void rendererChanged(const std::string& property, ObjectConverter& value) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called every frame with the time passed since the last frame.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void update(sf::Time elapsedTime) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Rearrange the text, making use of the given size of maximum text width.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rearrangeText();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Widget::Ptr clone() const override
        {
            return std::make_shared<Label>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        sf::String m_string;
        std::vector<Text> m_lines;

        unsigned int m_textSize = 18;
        sf::Uint32 m_textStyle = sf::Text::Style::Regular;
        HorizontalAlignment m_horizontalAlignment = HorizontalAlignment::Left;
        VerticalAlignment m_verticalAlignment = VerticalAlignment::Top;

        bool m_autoSize = true;

        float m_maximumTextWidth = 0;

        // Will be set to true after the first click, but gets reset to false when the second click does not occur soon after
        bool m_possibleDoubleClick = false;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_LABEL_HPP
