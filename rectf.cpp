#include "rectf.h"


    bool Rectf::pointInRect(const Point2f& pt) const noexcept
    {
        bool bX = right_bottom.x - pt.x >= left_top.x;
        bool bY = right_bottom.y - pt.y >= left_top.y;
        return (bX && bY);
    }

    Rectf::Rectf(const Rectf& r)
    {
        *this = r;
    }
    Rectf& Rectf::operator = (const Rectf& r)
    {
        if (this == &r) return *this;
        left_top = r.left_top;
        right_bottom = r.right_bottom;
        return *this;
    }
    void Rectf::heightByAspect(GLfloat aspect)
    {
        if(aspect == 0) return;
        right_bottom.y = right_bottom.x / aspect;
    }

    void Rectf::widthByAspect(GLfloat aspect)
    {
        if(aspect == 0) return;
        right_bottom.x = right_bottom.y * aspect;
    }
