/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_SPRITE_SHEET_HPP
#define TGUI_SPRITE_SHEET_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Load one big image and split it into smaller images so that you can display tiles or play an animation.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API SpriteSheet : public Picture
    {
      public:

        typedef SharedObjectPtr<SpriteSheet> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SpriteSheet();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SpriteSheet(const SpriteSheet& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SpriteSheet& operator= (const SpriteSheet& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the object by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual SpriteSheet* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the picture cell, so the piece that is shown.
        ///
        /// \param width   The new width of the picture cell.
        /// \param height  The new height of the picture cell.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of a picture cell, so the piece that is shown.
        ///
        /// \return Size of the cell
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the number of rows and columns in the image.
        ///
        /// \param rows     The amount of rows in the picture
        /// \param columns  The amount of columns in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCells(unsigned int rows, unsigned int columns);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the number of rows in the image.
        ///
        /// \param rows  The amount of rows in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setRows(unsigned int rows);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the number of rows in the image.
        ///
        /// \return The amount of rows in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getRows() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the number of columns in the image.
        ///
        /// \param columns  The amount of columns in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setColumns(unsigned int columns);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the number of columns in the image.
        ///
        /// \return The amount of columns in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getColumns() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Choose which cell should be displayed.
        ///
        /// \param row     The row in which the visible cell is located
        /// \param column  The column in which the visible cell is located
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVisibleCell(unsigned int row, unsigned int column);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns which cell is being displayed.
        ///
        /// \return A vector containing the row and column in which the visible cell is located
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::Vector2u getVisibleCell() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Because this class is derived from sf::Drawable, you can just call the draw function from your sf::RenderTarget.
        // This function will be called and it will draw the picture on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum SpriteSheetCallbacks
        {
            AllSpriteSheetCallbacks = PictureCallbacksCount - 1,
            SpriteSheetCallbacksCount = PictureCallbacksCount
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        unsigned int m_Rows;
        unsigned int m_Columns;

        sf::Vector2u m_VisibleCell;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SPRITE_SHEET_HPP

