#ifndef GUI_H
#define GUI_H

#include <core/constants.h>
#include <core/script.h>
#include <core/types.h>

#include <libraries/std.hpp>

namespace cap
{
    // --------- Class Widget -------------------------------//
    class GUIWidget : public Drawable
    {
    protected:
        Point m_pos, m_size;

        string m_name;
        int m_type;
        int m_rel_values;
        map<int, any> m_styles;

    public:
        GUIWidget(string name, int type);

        template<class T>
        T getStyle(int key) const
        {
            return any_cast<T>(m_styles.at(key));
        }
        void setStyle(int key, const Color& value);
        bool hasStyle(int key) const;
        
    };

    // --------- Class Form -------------------------------//
    class GUIForm : public GUIWidget
    {
    private:
       string m_title;
       int m_flags;
       vector<GUIWidget*> widgets;

       void draw(RenderTarget& target, RenderStates states) const;

    public:
        GUIForm(string name = string());

        void addWidget(GUIWidget* widget);

        void setTitle(string title);
        void setPosition(Point pos, int relative = NULL);
        void setSize(Point size, int relative = NULL);
    };

    // --------- Class Button -------------------------------//
    class GUIButton : public GUIWidget
    {
    private:
        string m_title;

    protected:
        void draw(RenderTarget& target, RenderStates states) const;

    public:
        // Callback
        LuaRef onClick = 0;

        // Methods
        GUIButton(string name = string());

        void setText(string title);
    };

    // --------- Class Label -------------------------------//
    class GUILabel : public GUIWidget
    {
    private:
        string m_title;

    protected:
        void draw(RenderTarget& target, RenderStates states) const;

    public:
        GUILabel(string name = string());

        void setText(string title);
    };

    // --------- Class Text -------------------------------//
    class GUIText : public GUIWidget
    {
    private:
        string m_title;

    protected:
        void draw(RenderTarget& target, RenderStates states) const;

    public:
        GUIText(string name = string());

        void setText(string title);
    };
}

#endif // GUI_H
