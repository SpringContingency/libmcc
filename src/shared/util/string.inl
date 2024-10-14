
inline void str_cpy(wchar_t* dst, const char* src) {
    while (*src) *dst++ = *src++;
}