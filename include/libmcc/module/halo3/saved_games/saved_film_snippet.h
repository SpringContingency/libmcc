#pragma once

namespace libmcc::halo3 {
    /*
    *s_saved_film_snippet_globals *__fastcall s_saved_film_snippet_globals::s_saved_film_snippet_globals(s_saved_film_snippet_globals *this)
{
  c_async_double_buffer::c_async_double_buffer(this);
  c_static_string<48>::c_static_string<48>((char *)this + 100);
  return this;
}
     *
     */

    struct s_saved_film_snippet_globals {
        struct {
            char data[128];
        } data2[4];

        char data[336];
    };

    static_assert(sizeof(s_saved_film_snippet_globals) == 848);
}