#pragma once

class c_saved_film_interface {
public:
    virtual void        free()        = 0;
    virtual void*       unknown_00()  = 0;
    virtual wchar_t*    unknown_01()  = 0;
    virtual void*       unknown_02()  = 0;
    virtual void*       unknown_03()  = 0;
    virtual int         unknown_04()  = 0;
    virtual int         unknown_05()  = 0;
    virtual bool        unknown_06()  = 0;
    virtual bool        unknown_07()  = 0;
    virtual void*       unknown_08()  = 0;
    virtual int         unknown_09()  = 0;
    virtual void*       unknown_10()  = 0;
    virtual void*       unknown_11()  = 0;
    virtual void*       unknown_12()  = 0;
    virtual __int64     unknown_13()  = 0;
    virtual void*       unknown_14()  = 0;
    virtual void*       unknown_15()  = 0;
    virtual void*       unknown_16()  = 0; // 6312
    virtual bool       get_info(char* buf, __int64* data)  = 0; // 7536
    virtual bool        copy_to(char* buf)  = 0;
};
