#pragma once

#include "native.h"

#include "./cache/cache_files.h"

namespace libmcc::halo1 {
    namespace ds {class BIT_STREAM {};}

    enum dsDATA_BINARY_OP : int {};
    enum dsDATA_CMP_RES : int {};
    enum dsCONVERTION_TYPE : int {};
    enum dsDATA_MATH_RES : int {};
    enum dsDATA_UNARY_OP : int {};

    template <typename T>
    struct dsTSTRING_BUF_HEADER {
        int refCount;
        int strLen;
        int maxStrLen;
        T str[1];
    };

    template <typename T>
    struct dsTSTRING {
        dsTSTRING_BUF_HEADER<T> *pBuffer;
    };

    class dsDATA_TYPE;

    struct dsDATA {
        unsigned int storage;
        const dsDATA_TYPE *type;
    };

    struct dsSTRID {
        const char *id;
    };

    class fioFILE {

    };

    class dsDATA_TYPE {
    public:
        virtual void Construct(unsigned int *) = 0;
        virtual void CopyConstruct(unsigned int *, const unsigned int *) = 0;
        virtual void ConstructFromObj(unsigned int *, const void *) = 0;
        virtual void Destroy(unsigned int *) = 0;
        virtual void Copy(const unsigned int *, unsigned int *) = 0;
        virtual void CopyObj(const void *, unsigned int *) = 0;
        virtual void *GetPtr(dsDATA*) = 0;
        virtual const void *GetPtr(const dsDATA*) const = 0;
        virtual int IsFunc(const dsDATA *, dsSTRID) = 0;
        virtual int IsProperty(const dsDATA *, dsSTRID) = 0;
        virtual int CallFunc(dsSTRID, dsDATA *, dsDATA *, int, dsDATA *) = 0;
        virtual int GetProperty(dsSTRID, const dsDATA *, dsDATA *) = 0;
        virtual int SetProperty(dsSTRID, dsDATA *, const dsDATA *) = 0;
        virtual int RawConvert(const void *, void *, const dsDATA_TYPE *, dsCONVERTION_TYPE) = 0;
        virtual int Convert(const unsigned int *, unsigned int *, const dsDATA_TYPE *, dsCONVERTION_TYPE) = 0;
        virtual const dsDATA_TYPE *MTSafeAnalog() = 0;
        virtual dsDATA_CMP_RES Compare(const unsigned int *, const unsigned int *, const dsDATA_TYPE *) = 0;
        virtual int Save(const unsigned int *, fioFILE *) = 0;
        virtual int Load(fioFILE *, unsigned int *) = 0;
        virtual void NetPack(const unsigned int *, ds::BIT_STREAM *, const dsDATA *) = 0;
        virtual void NetUnpack(ds::BIT_STREAM *, unsigned int *, const dsDATA *) = 0;
        virtual dsDATA_MATH_RES DoMathOp(dsDATA_UNARY_OP, const unsigned int *, dsDATA *) = 0;
        virtual dsDATA_MATH_RES DoMathOp(dsDATA_BINARY_OP, const unsigned int *, const unsigned int *, const dsDATA_TYPE *, dsDATA *) = 0;
        virtual int GetTypeId() = 0;
        virtual int IsMTSafe(const unsigned int *) = 0;
        virtual const char *GetDbgName() = 0;
        virtual dsTSTRING<char> *GetDbgString(dsTSTRING<char> *result, const unsigned int *) = 0;
        virtual int GetId() = 0;
        virtual ~dsDATA_TYPE() = 0;
    };

    struct dsSTATE_MGR {
        void SetState(int id, const dsDATA* data) {
			return INVOKE<void>(s_function_offset_table::dsSTATE_MGR__SetState, this, id, data);
        }

		int RegisterState(const char* id, bool isToggleEventOnChange) {
			return INVOKE<int>(s_function_offset_table::dsSTATE_MGR__RegisterState, this, id, isToggleEventOnChange);
		}

		const dsDATA* GetState(int id) {
			return INVOKE<const dsDATA*>(s_function_offset_table::dsSTATE_MGR__GetState, this, id);
		}
    };
}