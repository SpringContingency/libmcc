#pragma once

#include "../native.h"
#include "./tag_resource_threading.h"
#include "../multithreading/threads.h"

namespace libmcc::halo3 {
    struct s_tag_resouce {

    };

    struct c_cache_file_tag_resource_runtime_manager {
        c_wrapped_array<c_tag_resource_cache_file_access_cache*>* m_per_thread_access_cache() {
            return reinterpret_cast<c_wrapped_array<c_tag_resource_cache_file_access_cache*>*>(data + 0x2B9B0);
        };

        char data[1];
    };

    /* 1911 */
    struct c_basic_buffer
    {
        void *m_buffer;
        int m_size;
    };

    /* 3350 */
    struct c_typed_allocation_data_no_destruct_c_cache_file_tag_resource_runtime_manager_1 {
        c_basic_buffer m_opaque_storage;
        c_cache_file_tag_resource_runtime_manager *m_live_object;
        c_allocation_base *m_allocator;
    };

    inline c_typed_allocation_data_no_destruct_c_cache_file_tag_resource_runtime_manager_1* g_resource_runtime_manager() {
        return REF<c_typed_allocation_data_no_destruct_c_cache_file_tag_resource_runtime_manager_1>(_data_g_resource_runtime_manager);
    }

    struct s_tag_resource {
        union {
            int resource_handle;
            int resource_data;
        };
        int definition_address;

        template <typename T>
        T* get() {
            auto thread_index = g_thread_local_storage()->g_registered_thread_index;

            auto mananger = g_resource_runtime_manager();

            if (reinterpret_cast<int64_t>(mananger->m_live_object) == -177216) {
                return nullptr;
            }

            auto access_cache = mananger->m_live_object->m_per_thread_access_cache()->m_elements[thread_index];

            auto index = static_cast<uint16_t>(resource_handle);

            return reinterpret_cast<T*>(access_cache->m_cached_access_datums.m_elements[index]);
        }
    };
}
