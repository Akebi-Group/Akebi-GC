// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Helper functions

#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include <cheat-base/Logger.h>

#include "il2cpp-metadata-version.h"

#define IS_SINGLETON_LOADED(className) (/**app::Singleton_1_## className ##___TypeInfo != nullptr &&*/ *app::Singleton_1_ ## className ## __get_Instance__MethodInfo != nullptr)
#define GET_SINGLETON(tpname) IS_SINGLETON_LOADED(tpname) ? reinterpret_cast<app:: ## tpname ## *>(app::Singleton_GetInstance(*app::Singleton_1_ ## tpname ## __get_Instance__MethodInfo)) : nullptr

#define INIT_ILCPP_CLASS(className, expr) (il2cpp_runtime_class_init(reinterpret_cast<Il2CppClass*>(*app::## className ##__TypeInfo)), expr)
#define GET_STATIC_FIELDS(tpname) INIT_ILCPP_CLASS(tpname, (*app::## tpname ##__TypeInfo)->static_fields)

#define SAFE_BEGIN() __try {
#define SAFE_ERROR() } __except (EXCEPTION_EXECUTE_HANDLER) { \
LOG_WARNING("Exception 0x%08x.", GetExceptionCode());

#define SAFE_END() }
#define SAFE_EEND() SAFE_ERROR(); SAFE_END();

#define COMMA ,
#define TO_UNI_COLLECTION(field, collection) reinterpret_cast<collection*>(field)
#define TO_UNI_ARRAY(field, type) TO_UNI_COLLECTION(field, UniArray<type>)
#define TO_UNI_LIST(field, type) TO_UNI_COLLECTION(field, UniList<type>)
#define TO_UNI_LINK_LIST(field, type) TO_UNI_COLLECTION(field, UniLinkList<type>)
#define TO_UNI_DICT(field, keyType, valueType) TO_UNI_COLLECTION(field, UniDict<keyType COMMA valueType>)

template<class ElementT>
struct UniLinkList;

template<class ElementT>
struct UniLinkListNode
{
    ElementT item;
    UniLinkList<ElementT>* container;
    UniLinkListNode<ElementT>* forward;
    UniLinkListNode<ElementT>* back;
};

template<class ElementT>
struct UniLinkList
{
    void* klass;
    MonitorData* monitor;
    uint32_t count;
    uint32_t version;
    app::Object* syncRoot;
    UniLinkListNode<ElementT>* first;
    struct SerializationInfo* si;
};

template<typename ElementT>
struct UniArray {
    void* klass;
    MonitorData* monitor;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    ElementT vector[32];

    typedef ElementT* iterator;
    typedef const ElementT* const_iterator;

    size_t length() const { return (bounds == nullptr) ? max_length : bounds->length; }

    iterator begin() { return &vector[0]; }
    const_iterator begin() const { return &vector[0]; }
    iterator end() { return &vector[length()]; }
    const_iterator end() const { return &vector[length()]; }
    ElementT* operator[](int i) { return &vector[i]; }

    std::vector<ElementT> vec()
    {
        auto result = std::vector<ElementT>(length());
        for (auto i = begin(); i < end(); i++)
            result.push_back(*i);
        return result;
    }
};

template <typename T>
struct UniList
{
    void* klass;
    void* monitor;
    UniArray<T>* store;
    int32_t size;
    int32_t version;

    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() { return (*store)[0]; }
    const_iterator begin() const { return (*store)[0]; }
    iterator end() { return (*store)[size]; }
    const_iterator end() const { return (*store)[size]; }

    std::vector<T> vec()
    {
        auto result = std::vector<T>();
        result.reserve(size);
        for (auto i = begin(); i < end(); i++)
            result.push_back(*i);
        return result;
    }
};

template<typename KeyT, typename ValT>
struct UniDictEntry
{
    int32_t hashCode;
    int32_t next;
    KeyT key;
    ValT value;
};

template<typename KeyT, typename ValT>
struct __declspec(align(8)) UniDict {
    void* klass;
    MonitorData* monitor;
    void* buckets;
    UniArray<UniDictEntry<KeyT, ValT>>* entries;
    int32_t count;
    int32_t version;
    int32_t freeList;
    int32_t freeCount;
    void* comparer;
    void* keys;
    void* values;

    std::vector<std::pair<KeyT, ValT>> pairs()
    {
        auto pairs = std::vector<std::pair<KeyT, ValT>>();

#define DictCheckNull(field, msg) if (field == nullptr) { /*LOG_WARNING("Failed to get dict pairs: %s", msg);*/ return pairs; }

        DictCheckNull(buckets, "Buckets is null.");
        DictCheckNull(entries, "Entries is null.");

#undef DictCheckNull

        int32_t index = 0;
        for (auto& entry : *entries)
        {
            if (index >= count)
                break;

            if (entry.hashCode > 0)
                pairs.push_back({ entry.key, entry.value });

            index++;
        }

        return pairs;
    }
};

template<class T>
T* CastTo(void* pObject, void* pClass)
{
    auto object = reinterpret_cast<app::Object*>(pObject);
    if (object == nullptr || object->klass == nullptr || object->klass != pClass)
        return nullptr;

    return reinterpret_cast<T*>(object);
}

inline app::Vector3 operator + (const app::Vector3& A, const app::Vector3& B)
{
    return { A.x + B.x, A.y + B.y, A.z + B.z };
}

inline app::Vector3 operator + (const app::Vector3& A, const float k)
{
    return { A.x + k, A.y + k, A.z + k };
}

inline app::Vector3 operator - (const app::Vector3& A, const app::Vector3& B)
{
    return { A.x - B.x, A.y - B.y, A.z - B.z };
}

inline app::Vector3 operator - (const app::Vector3& A, const float k)
{
    return { A.x - k, A.y - k, A.z - k };
}

inline app::Vector3 operator * (const app::Vector3& A, const float k)
{
    return { A.x * k, A.y * k, A.z * k };
}

inline app::Vector3 operator / (const app::Vector3& A, const float k)
{
    return { A.x / k, A.y / k, A.z / k };
}

inline app::Vector3 operator - (const app::Vector3& A)
{
    return { -A.x, -A.y, -A.z };
}

inline app::Vector2 operator + (const app::Vector2& A, const float k)
{
    return { A.x + k, A.y + k };
}

inline app::Vector2 operator - (const app::Vector2& A, const app::Vector2& B)
{
    return { A.x - B.x, A.y - B.y };
}

inline app::Vector2 operator - (const app::Vector2& A, const float k)
{
    return { A.x - k, A.y - k };
}

inline app::Vector2 operator + (const app::Vector2& A, const app::Vector2& B)
{
    return { A.x + B.x, A.y + B.y };
}

inline app::Vector2 operator * (const app::Vector2& A, const float k)
{
    return { A.x * k, A.y * k };
}

inline app::Vector2 operator * (const app::Vector2& A, const app::Vector2& B)
{
    return { A.x * B.x, A.y * B.y };
}

inline app::Vector2 operator / (const app::Vector2& A, const float k)
{
    return { A.x / k, A.y / k };
}

inline app::Vector2 operator - (const app::Vector2& A)
{
    return { -A.x, -A.y };
}

inline float GetVectorMagnitude(const app::Vector3& A)
{
    return sqrtf(A.x * A.x + A.y * A.y + A.z * A.z);
}

inline app::Vector3 GetVectorDirection(const app::Vector3& from, const app::Vector3& to)
{
    auto dirRaw = to - from;
    return dirRaw / GetVectorMagnitude(dirRaw);
}

inline bool IsVectorZero(const app::Vector3& vector)
{
    return vector.x == 0 && vector.y == 0 && vector.z == 0;
}

// Helper function to get mono module base address
uintptr_t il2cpp_get_mono_base_address();

// Helper function to get the module base address
uintptr_t il2cppi_get_base_address();

// Helper function to get the UnityPlayer.dll base address
uintptr_t il2cppi_get_unity_address();

// Helper function to open a new console window and redirect stdout there
void il2cppi_new_console();
void il2cppi_close_console();

#if _MSC_VER >= 1920
std::string il2cppi_to_string(Il2CppString* str);
std::string il2cppi_to_string(app::String* str);
std::string il2cppi_to_string(app::Vector vec);
std::string il2cppi_to_string(app::Vector2 vec);
std::string il2cppi_to_string(app::Vector3 vec);
app::String* string_to_il2cppi(std::string input);
std::string to_hex_string(app::Byte__Array* barray, int length);
#endif

// Helper function to check if a metadata usage pointer is initialized
template<typename T> bool il2cppi_is_initialized(T* metadataItem) {
#if __IL2CPP_METADATA_VERISON < 270
    return *metadataItem != 0;
#else
    // Metadata >=27 (Unity 2020.2)
    return !((uintptr_t)*metadataItem & 1);
#endif
}
