
// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2019.4.21 - 2019.4.24

#if defined(_GHIDRA_) || defined(_IDA_)
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
#endif

#if defined(_GHIDRA_)
typedef __int64 size_t;
typedef size_t intptr_t;
typedef size_t uintptr_t;
#endif

#if !defined(_GHIDRA_) && !defined(_IDA_)
#define _CPLUSPLUS_
#endif

// ******************************************************************************
// * IL2CPP internal types
// ******************************************************************************

typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppType Il2CppType;
typedef struct EventInfo EventInfo;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppArray Il2CppArray;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppProfiler Il2CppProfiler;
typedef struct Il2CppObject Il2CppObject;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppReflectionType Il2CppReflectionType;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppThread Il2CppThread;
typedef struct Il2CppAsyncResult Il2CppAsyncResult;
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef struct Il2CppCustomAttrInfo Il2CppCustomAttrInfo;
typedef enum
{
    IL2CPP_PROFILE_NONE = 0,
    IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
    IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
    IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
    IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
    IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
    IL2CPP_PROFILE_INLINING = 1 << 5,
    IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
    IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
    IL2CPP_PROFILE_GC = 1 << 8,
    IL2CPP_PROFILE_THREADS = 1 << 9,
    IL2CPP_PROFILE_REMOTING = 1 << 10,
    IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
    IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
    IL2CPP_PROFILE_COVERAGE = 1 << 13,
    IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
    IL2CPP_PROFILE_STATISTICAL = 1 << 15,
    IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
    IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
    IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18,
    IL2CPP_PROFILE_GC_MOVES = 1 << 19,
    IL2CPP_PROFILE_FILEIO = 1 << 20
} Il2CppProfileFlags;
typedef enum
{
    IL2CPP_PROFILE_FILEIO_WRITE = 0,
    IL2CPP_PROFILE_FILEIO_READ
} Il2CppProfileFileIOKind;
typedef enum
{
    IL2CPP_GC_EVENT_START,
    IL2CPP_GC_EVENT_MARK_START,
    IL2CPP_GC_EVENT_MARK_END,
    IL2CPP_GC_EVENT_RECLAIM_START,
    IL2CPP_GC_EVENT_RECLAIM_END,
    IL2CPP_GC_EVENT_END,
    IL2CPP_GC_EVENT_PRE_STOP_WORLD,
    IL2CPP_GC_EVENT_POST_STOP_WORLD,
    IL2CPP_GC_EVENT_PRE_START_WORLD,
    IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;
typedef enum
{
    IL2CPP_STAT_NEW_OBJECT_COUNT,
    IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
    IL2CPP_STAT_METHOD_COUNT,
    IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
    IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
    IL2CPP_STAT_GENERIC_CLASS_COUNT,
    IL2CPP_STAT_INFLATED_METHOD_COUNT,
    IL2CPP_STAT_INFLATED_TYPE_COUNT,
} Il2CppStat;
typedef enum
{
    IL2CPP_UNHANDLED_POLICY_LEGACY,
    IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;
typedef struct Il2CppStackFrameInfo
{
    const MethodInfo *method;
} Il2CppStackFrameInfo;
typedef void(*Il2CppMethodPointer)();
typedef struct Il2CppMethodDebugInfo
{
    Il2CppMethodPointer methodPointer;
    int32_t code_size;
    const char *file;
} Il2CppMethodDebugInfo;
typedef struct
{
    void* (*malloc_func)(size_t size);
    void* (*aligned_malloc_func)(size_t size, size_t alignment);
    void (*free_func)(void *ptr);
    void (*aligned_free_func)(void *ptr);
    void* (*calloc_func)(size_t nmemb, size_t size);
    void* (*realloc_func)(void *ptr, size_t size);
    void* (*aligned_realloc_func)(void *ptr, size_t size, size_t alignment);
} Il2CppMemoryCallbacks;
typedef struct
{
    const char *name;
    void(*connect)(const char *address);
    int(*wait_for_attach)(void);
    void(*close1)(void);
    void(*close2)(void);
    int(*send)(void *buf, int len);
    int(*recv)(void *buf, int len);
} Il2CppDebuggerTransport;
typedef uint16_t Il2CppChar;
typedef char Il2CppNativeChar;
typedef void (*il2cpp_register_object_callback)(Il2CppObject** arr, int size, void* userdata);
typedef void (*il2cpp_WorldChangedCallback)();
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo *info, void *user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo *method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject *obj, Il2CppClass *klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef void (*Il2CppProfileFileIOFunc) (Il2CppProfiler* prof, Il2CppProfileFileIOKind kind, int count);
typedef void (*Il2CppProfileThreadFunc) (Il2CppProfiler *prof, unsigned long tid);
typedef const Il2CppNativeChar* (*Il2CppSetFindPlugInCallback)(const Il2CppNativeChar*);
typedef void (*Il2CppLogCallback)(const char*);
typedef size_t(*Il2CppBacktraceFunc) (Il2CppMethodPointer* buffer, size_t maxSize);
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef uintptr_t il2cpp_array_size_t;
typedef void ( *SynchronizationContextCallback)(intptr_t arg);
typedef uint32_t Il2CppMethodSlot;
static const uint32_t kInvalidIl2CppMethodSlot = 65535;
static const int ipv6AddressSize = 16;
typedef int32_t il2cpp_hresult_t;
typedef struct Il2CppMetadataField
{
    uint32_t offset;
    uint32_t typeIndex;
    const char* name;
    uint8_t isStatic;
} Il2CppMetadataField;
typedef enum Il2CppMetadataTypeFlags
{
    kNone = 0,
    kValueType = 1 << 0,
    kArray = 1 << 1,
    kArrayRankMask = 0xFFFF0000
} Il2CppMetadataTypeFlags;
typedef struct Il2CppMetadataType
{
    Il2CppMetadataTypeFlags flags;
    Il2CppMetadataField* fields;
    uint32_t fieldCount;
    uint32_t staticsSize;
    uint8_t* statics;
    uint32_t baseOrElementTypeIndex;
    char* name;
    const char* assemblyName;
    uint64_t typeInfoAddress;
    uint32_t size;
} Il2CppMetadataType;
typedef struct Il2CppMetadataSnapshot
{
    uint32_t typeCount;
    Il2CppMetadataType* types;
} Il2CppMetadataSnapshot;
typedef struct Il2CppManagedMemorySection
{
    uint64_t sectionStartAddress;
    uint32_t sectionSize;
    uint8_t* sectionBytes;
} Il2CppManagedMemorySection;
typedef struct Il2CppManagedHeap
{
    uint32_t sectionCount;
    Il2CppManagedMemorySection* sections;
} Il2CppManagedHeap;
typedef struct Il2CppStacks
{
    uint32_t stackCount;
    Il2CppManagedMemorySection* stacks;
} Il2CppStacks;
typedef struct NativeObject
{
    uint32_t gcHandleIndex;
    uint32_t size;
    uint32_t instanceId;
    uint32_t classId;
    uint32_t referencedNativeObjectIndicesCount;
    uint32_t* referencedNativeObjectIndices;
} NativeObject;
typedef struct Il2CppGCHandles
{
    uint32_t trackedObjectCount;
    uint64_t* pointersToObjects;
} Il2CppGCHandles;
typedef struct Il2CppRuntimeInformation
{
    uint32_t pointerSize;
    uint32_t objectHeaderSize;
    uint32_t arrayHeaderSize;
    uint32_t arrayBoundsOffsetInHeader;
    uint32_t arraySizeOffsetInHeader;
    uint32_t allocationGranularity;
} Il2CppRuntimeInformation;
typedef struct Il2CppManagedMemorySnapshot
{
    Il2CppManagedHeap heap;
    Il2CppStacks stacks;
    Il2CppMetadataSnapshot metadata;
    Il2CppGCHandles gcHandles;
    Il2CppRuntimeInformation runtimeInformation;
    void* additionalUserInformation;
} Il2CppManagedMemorySnapshot;
typedef enum Il2CppTypeEnum
{
    IL2CPP_TYPE_END = 0x00,
    IL2CPP_TYPE_VOID = 0x01,
    IL2CPP_TYPE_BOOLEAN = 0x02,
    IL2CPP_TYPE_CHAR = 0x03,
    IL2CPP_TYPE_I1 = 0x04,
    IL2CPP_TYPE_U1 = 0x05,
    IL2CPP_TYPE_I2 = 0x06,
    IL2CPP_TYPE_U2 = 0x07,
    IL2CPP_TYPE_I4 = 0x08,
    IL2CPP_TYPE_U4 = 0x09,
    IL2CPP_TYPE_I8 = 0x0a,
    IL2CPP_TYPE_U8 = 0x0b,
    IL2CPP_TYPE_R4 = 0x0c,
    IL2CPP_TYPE_R8 = 0x0d,
    IL2CPP_TYPE_STRING = 0x0e,
    IL2CPP_TYPE_PTR = 0x0f,
    IL2CPP_TYPE_BYREF = 0x10,
    IL2CPP_TYPE_VALUETYPE = 0x11,
    IL2CPP_TYPE_CLASS = 0x12,
    IL2CPP_TYPE_VAR = 0x13,
    IL2CPP_TYPE_ARRAY = 0x14,
    IL2CPP_TYPE_GENERICINST = 0x15,
    IL2CPP_TYPE_TYPEDBYREF = 0x16,
    IL2CPP_TYPE_I = 0x18,
    IL2CPP_TYPE_U = 0x19,
    IL2CPP_TYPE_FNPTR = 0x1b,
    IL2CPP_TYPE_OBJECT = 0x1c,
    IL2CPP_TYPE_SZARRAY = 0x1d,
    IL2CPP_TYPE_MVAR = 0x1e,
    IL2CPP_TYPE_CMOD_REQD = 0x1f,
    IL2CPP_TYPE_CMOD_OPT = 0x20,
    IL2CPP_TYPE_INTERNAL = 0x21,
    IL2CPP_TYPE_MODIFIER = 0x40,
    IL2CPP_TYPE_SENTINEL = 0x41,
    IL2CPP_TYPE_PINNED = 0x45,
    IL2CPP_TYPE_ENUM = 0x55
} Il2CppTypeEnum;
typedef enum
{
    IL2CPP_TOKEN_MODULE = 0x00000000,
    IL2CPP_TOKEN_TYPE_REF = 0x01000000,
    IL2CPP_TOKEN_TYPE_DEF = 0x02000000,
    IL2CPP_TOKEN_FIELD_DEF = 0x04000000,
    IL2CPP_TOKEN_METHOD_DEF = 0x06000000,
    IL2CPP_TOKEN_PARAM_DEF = 0x08000000,
    IL2CPP_TOKEN_INTERFACE_IMPL = 0x09000000,
    IL2CPP_TOKEN_MEMBER_REF = 0x0a000000,
    IL2CPP_TOKEN_CUSTOM_ATTRIBUTE = 0x0c000000,
    IL2CPP_TOKEN_PERMISSION = 0x0e000000,
    IL2CPP_TOKEN_SIGNATURE = 0x11000000,
    IL2CPP_TOKEN_EVENT = 0x14000000,
    IL2CPP_TOKEN_PROPERTY = 0x17000000,
    IL2CPP_TOKEN_MODULE_REF = 0x1a000000,
    IL2CPP_TOKEN_TYPE_SPEC = 0x1b000000,
    IL2CPP_TOKEN_ASSEMBLY = 0x20000000,
    IL2CPP_TOKEN_ASSEMBLY_REF = 0x23000000,
    IL2CPP_TOKEN_FILE = 0x26000000,
    IL2CPP_TOKEN_EXPORTED_TYPE = 0x27000000,
    IL2CPP_TOKEN_MANIFEST_RESOURCE = 0x28000000,
    IL2CPP_TOKEN_GENERIC_PARAM = 0x2a000000,
    IL2CPP_TOKEN_METHOD_SPEC = 0x2b000000,
} Il2CppTokenType;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t InteropDataIndex;
static const TypeIndex kTypeIndexInvalid = -1;
static const TypeDefinitionIndex kTypeDefinitionIndexInvalid = -1;
static const DefaultValueDataIndex kDefaultValueIndexNull = -1;
static const CustomAttributeIndex kCustomAttributeIndexInvalid = -1;
static const EventIndex kEventIndexInvalid = -1;
static const FieldIndex kFieldIndexInvalid = -1;
static const MethodIndex kMethodIndexInvalid = -1;
static const PropertyIndex kPropertyIndexInvalid = -1;
static const GenericContainerIndex kGenericContainerIndexInvalid = -1;
static const GenericParameterIndex kGenericParameterIndexInvalid = -1;
static const RGCTXIndex kRGCTXIndexInvalid = -1;
static const StringLiteralIndex kStringLiteralIndexInvalid = -1;
static const InteropDataIndex kInteropDataIndexInvalid = -1;
typedef uint32_t EncodedMethodIndex;
typedef enum Il2CppMetadataUsage
{
    kIl2CppMetadataUsageInvalid,
    kIl2CppMetadataUsageTypeInfo,
    kIl2CppMetadataUsageIl2CppType,
    kIl2CppMetadataUsageMethodDef,
    kIl2CppMetadataUsageFieldInfo,
    kIl2CppMetadataUsageStringLiteral,
    kIl2CppMetadataUsageMethodRef,
} Il2CppMetadataUsage;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppTypeDefinitionMetadata Il2CppTypeDefinitionMetadata;
typedef union Il2CppRGCTXDefinitionData
{
    int32_t rgctxDataDummy;
    MethodIndex methodIndex;
    TypeIndex typeIndex;
} Il2CppRGCTXDefinitionData;
typedef enum Il2CppRGCTXDataType
{
    IL2CPP_RGCTX_DATA_INVALID,
    IL2CPP_RGCTX_DATA_TYPE,
    IL2CPP_RGCTX_DATA_CLASS,
    IL2CPP_RGCTX_DATA_METHOD,
    IL2CPP_RGCTX_DATA_ARRAY,
} Il2CppRGCTXDataType;
typedef struct Il2CppRGCTXDefinition
{
    Il2CppRGCTXDataType type;
    Il2CppRGCTXDefinitionData data;
} Il2CppRGCTXDefinition;
typedef struct Il2CppInterfaceOffsetPair
{
    TypeIndex interfaceTypeIndex;
    int32_t offset;
} Il2CppInterfaceOffsetPair;
typedef struct Il2CppTypeDefinition
{
    StringIndex nameIndex;
    StringIndex namespaceIndex;
    TypeIndex byvalTypeIndex;
    TypeIndex byrefTypeIndex;
    TypeIndex declaringTypeIndex;
    TypeIndex parentIndex;
    TypeIndex elementTypeIndex;
    GenericContainerIndex genericContainerIndex;
    uint32_t flags;
    FieldIndex fieldStart;
    MethodIndex methodStart;
    EventIndex eventStart;
    PropertyIndex propertyStart;
    NestedTypeIndex nestedTypesStart;
    InterfacesIndex interfacesStart;
    VTableIndex vtableStart;
    InterfacesIndex interfaceOffsetsStart;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint32_t bitfield;
    uint32_t token;
} Il2CppTypeDefinition;
typedef struct Il2CppFieldDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    uint32_t token;
} Il2CppFieldDefinition;
typedef struct Il2CppFieldDefaultValue
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;
typedef struct Il2CppFieldMarshaledSize
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    int32_t size;
} Il2CppFieldMarshaledSize;
typedef struct Il2CppFieldRef
{
    TypeIndex typeIndex;
    FieldIndex fieldIndex;
} Il2CppFieldRef;
typedef struct Il2CppParameterDefinition
{
    StringIndex nameIndex;
    uint32_t token;
    TypeIndex typeIndex;
} Il2CppParameterDefinition;
typedef struct Il2CppParameterDefaultValue
{
    ParameterIndex parameterIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;
typedef struct Il2CppMethodDefinition
{
    StringIndex nameIndex;
    TypeDefinitionIndex declaringType;
    TypeIndex returnType;
    ParameterIndex parameterStart;
    GenericContainerIndex genericContainerIndex;
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint16_t parameterCount;
} Il2CppMethodDefinition;
typedef struct Il2CppEventDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    MethodIndex add;
    MethodIndex remove;
    MethodIndex raise;
    uint32_t token;
} Il2CppEventDefinition;
typedef struct Il2CppPropertyDefinition
{
    StringIndex nameIndex;
    MethodIndex get;
    MethodIndex set;
    uint32_t attrs;
    uint32_t token;
} Il2CppPropertyDefinition;
typedef struct Il2CppMethodSpec
{
    MethodIndex methodDefinitionIndex;
    GenericInstIndex classIndexIndex;
    GenericInstIndex methodIndexIndex;
} Il2CppMethodSpec;
typedef struct Il2CppStringLiteral
{
    uint32_t length;
    StringLiteralIndex dataIndex;
} Il2CppStringLiteral;
typedef struct
{
    MethodIndex methodIndex;
    MethodIndex invokerIndex;
    MethodIndex adjustorThunkIndex;
} Il2CppGenericMethodIndices;
typedef struct Il2CppGenericMethodFunctionsDefinitions
{
    GenericMethodIndex genericMethodIndex;
    Il2CppGenericMethodIndices indices;
} Il2CppGenericMethodFunctionsDefinitions;
static const int kPublicKeyByteLength = 8;
typedef struct Il2CppAssemblyNameDefinition
{
    StringIndex nameIndex;
    StringIndex cultureIndex;
    StringIndex publicKeyIndex;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[8];
} Il2CppAssemblyNameDefinition;
typedef struct Il2CppImageDefinition
{
    StringIndex nameIndex;
    AssemblyIndex assemblyIndex;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    MethodIndex entryPointIndex;
    uint32_t token;
    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
} Il2CppImageDefinition;
typedef struct Il2CppAssemblyDefinition
{
    ImageIndex imageIndex;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyNameDefinition aname;
} Il2CppAssemblyDefinition;
typedef struct Il2CppMetadataUsageList
{
    uint32_t start;
    uint32_t count;
} Il2CppMetadataUsageList;
typedef struct Il2CppMetadataUsagePair
{
    uint32_t destinationIndex;
    uint32_t encodedSourceIndex;
} Il2CppMetadataUsagePair;
typedef struct Il2CppCustomAttributeTypeRange
{
    uint32_t token;
    int32_t start;
    int32_t count;
} Il2CppCustomAttributeTypeRange;
typedef struct Il2CppRange
{
    int32_t start;
    int32_t length;
} Il2CppRange;
typedef struct Il2CppWindowsRuntimeTypeNamePair
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
} Il2CppWindowsRuntimeTypeNamePair;
#pragma pack(push, p1,4)
typedef struct Il2CppGlobalMetadataHeader
{
    int32_t sanity;
    int32_t version;
    int32_t stringLiteralOffset;
    int32_t stringLiteralCount;
    int32_t stringLiteralDataOffset;
    int32_t stringLiteralDataCount;
    int32_t stringOffset;
    int32_t stringCount;
    int32_t eventsOffset;
    int32_t eventsCount;
    int32_t propertiesOffset;
    int32_t propertiesCount;
    int32_t methodsOffset;
    int32_t methodsCount;
    int32_t parameterDefaultValuesOffset;
    int32_t parameterDefaultValuesCount;
    int32_t fieldDefaultValuesOffset;
    int32_t fieldDefaultValuesCount;
    int32_t fieldAndParameterDefaultValueDataOffset;
    int32_t fieldAndParameterDefaultValueDataCount;
    int32_t fieldMarshaledSizesOffset;
    int32_t fieldMarshaledSizesCount;
    int32_t parametersOffset;
    int32_t parametersCount;
    int32_t fieldsOffset;
    int32_t fieldsCount;
    int32_t genericParametersOffset;
    int32_t genericParametersCount;
    int32_t genericParameterConstraintsOffset;
    int32_t genericParameterConstraintsCount;
    int32_t genericContainersOffset;
    int32_t genericContainersCount;
    int32_t nestedTypesOffset;
    int32_t nestedTypesCount;
    int32_t interfacesOffset;
    int32_t interfacesCount;
    int32_t vtableMethodsOffset;
    int32_t vtableMethodsCount;
    int32_t interfaceOffsetsOffset;
    int32_t interfaceOffsetsCount;
    int32_t typeDefinitionsOffset;
    int32_t typeDefinitionsCount;
    int32_t imagesOffset;
    int32_t imagesCount;
    int32_t assembliesOffset;
    int32_t assembliesCount;
    int32_t metadataUsageListsOffset;
    int32_t metadataUsageListsCount;
    int32_t metadataUsagePairsOffset;
    int32_t metadataUsagePairsCount;
    int32_t fieldRefsOffset;
    int32_t fieldRefsCount;
    int32_t referencedAssembliesOffset;
    int32_t referencedAssembliesCount;
    int32_t attributesInfoOffset;
    int32_t attributesInfoCount;
    int32_t attributeTypesOffset;
    int32_t attributeTypesCount;
    int32_t unresolvedVirtualCallParameterTypesOffset;
    int32_t unresolvedVirtualCallParameterTypesCount;
    int32_t unresolvedVirtualCallParameterRangesOffset;
    int32_t unresolvedVirtualCallParameterRangesCount;
    int32_t windowsRuntimeTypeNamesOffset;
    int32_t windowsRuntimeTypeNamesSize;
    int32_t exportedTypeDefinitionsOffset;
    int32_t exportedTypeDefinitionsCount;
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppArrayType
{
    const Il2CppType* etype;
    uint8_t rank;
    uint8_t numsizes;
    uint8_t numlobounds;
    int *sizes;
    int *lobounds;
} Il2CppArrayType;
typedef struct Il2CppGenericInst
{
    uint32_t type_argc;
    const Il2CppType **type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
    const Il2CppGenericInst *class_inst;
    const Il2CppGenericInst *method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericParameter
{
    GenericContainerIndex ownerIndex;
    StringIndex nameIndex;
    GenericParameterConstraintIndex constraintsStart;
    int16_t constraintsCount;
    uint16_t num;
    uint16_t flags;
} Il2CppGenericParameter;
typedef struct Il2CppGenericContainer
{
    int32_t ownerIndex;
    int32_t type_argc;
    int32_t is_method;
    GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;
typedef struct Il2CppGenericClass
{
    TypeDefinitionIndex typeDefinitionIndex;
    Il2CppGenericContext context;
    Il2CppClass *cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
    const MethodInfo* methodDefinition;
    Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppType
{
    union
    {
        void* dummy;
        TypeDefinitionIndex klassIndex;
        const Il2CppType *type;
        Il2CppArrayType *array;
        GenericParameterIndex genericParameterIndex;
        Il2CppGenericClass *generic_class;
    } data;
    unsigned int attrs : 16;
    Il2CppTypeEnum type : 8;
    unsigned int num_mods : 6;
    unsigned int byref : 1;
    unsigned int pinned : 1;
} Il2CppType;
typedef enum Il2CppCallConvention
{
    IL2CPP_CALL_DEFAULT,
    IL2CPP_CALL_C,
    IL2CPP_CALL_STDCALL,
    IL2CPP_CALL_THISCALL,
    IL2CPP_CALL_FASTCALL,
    IL2CPP_CALL_VARARG
} Il2CppCallConvention;
typedef enum Il2CppCharSet
{
    CHARSET_ANSI,
    CHARSET_UNICODE,
    CHARSET_NOT_SPECIFIED
} Il2CppCharSet;
typedef struct Il2CppHString__
{
    int unused;
} Il2CppHString__;
typedef Il2CppHString__* Il2CppHString;
typedef struct Il2CppHStringHeader
{
    union
    {
        void* Reserved1;
        char Reserved2[24];
    } Reserved;
} Il2CppHStringHeader;
typedef struct Il2CppGuid
{
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
} Il2CppGuid;
typedef struct Il2CppSafeArrayBound
{
    uint32_t element_count;
    int32_t lower_bound;
} Il2CppSafeArrayBound;
typedef struct Il2CppSafeArray
{
    uint16_t dimension_count;
    uint16_t features;
    uint32_t element_size;
    uint32_t lock_count;
    void* data;
    Il2CppSafeArrayBound bounds[1];
} Il2CppSafeArray;
typedef struct Il2CppWin32Decimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } s;
        uint16_t signscale;
    } u;
    uint32_t hi32;
    union
    {
        struct
        {
            uint32_t lo32;
            uint32_t mid32;
        } s2;
        uint64_t lo64;
    } u2;
} Il2CppWin32Decimal;
typedef int16_t IL2CPP_VARIANT_BOOL;
typedef enum Il2CppVarType
{
    IL2CPP_VT_EMPTY = 0,
    IL2CPP_VT_NULL = 1,
    IL2CPP_VT_I2 = 2,
    IL2CPP_VT_I4 = 3,
    IL2CPP_VT_R4 = 4,
    IL2CPP_VT_R8 = 5,
    IL2CPP_VT_CY = 6,
    IL2CPP_VT_DATE = 7,
    IL2CPP_VT_BSTR = 8,
    IL2CPP_VT_DISPATCH = 9,
    IL2CPP_VT_ERROR = 10,
    IL2CPP_VT_BOOL = 11,
    IL2CPP_VT_VARIANT = 12,
    IL2CPP_VT_UNKNOWN = 13,
    IL2CPP_VT_DECIMAL = 14,
    IL2CPP_VT_I1 = 16,
    IL2CPP_VT_UI1 = 17,
    IL2CPP_VT_UI2 = 18,
    IL2CPP_VT_UI4 = 19,
    IL2CPP_VT_I8 = 20,
    IL2CPP_VT_UI8 = 21,
    IL2CPP_VT_INT = 22,
    IL2CPP_VT_UINT = 23,
    IL2CPP_VT_VOID = 24,
    IL2CPP_VT_HRESULT = 25,
    IL2CPP_VT_PTR = 26,
    IL2CPP_VT_SAFEARRAY = 27,
    IL2CPP_VT_CARRAY = 28,
    IL2CPP_VT_USERDEFINED = 29,
    IL2CPP_VT_LPSTR = 30,
    IL2CPP_VT_LPWSTR = 31,
    IL2CPP_VT_RECORD = 36,
    IL2CPP_VT_INT_PTR = 37,
    IL2CPP_VT_UINT_PTR = 38,
    IL2CPP_VT_FILETIME = 64,
    IL2CPP_VT_BLOB = 65,
    IL2CPP_VT_STREAM = 66,
    IL2CPP_VT_STORAGE = 67,
    IL2CPP_VT_STREAMED_OBJECT = 68,
    IL2CPP_VT_STORED_OBJECT = 69,
    IL2CPP_VT_BLOB_OBJECT = 70,
    IL2CPP_VT_CF = 71,
    IL2CPP_VT_CLSID = 72,
    IL2CPP_VT_VERSIONED_STREAM = 73,
    IL2CPP_VT_BSTR_BLOB = 0xfff,
    IL2CPP_VT_VECTOR = 0x1000,
    IL2CPP_VT_ARRAY = 0x2000,
    IL2CPP_VT_BYREF = 0x4000,
    IL2CPP_VT_RESERVED = 0x8000,
    IL2CPP_VT_ILLEGAL = 0xffff,
    IL2CPP_VT_ILLEGALMASKED = 0xfff,
    IL2CPP_VT_TYPEMASK = 0xfff,
} Il2CppVarType;
typedef struct Il2CppVariant Il2CppVariant;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppVariant
{
    union
    {
        struct __tagVARIANT
        {
            uint16_t type;
            uint16_t reserved1;
            uint16_t reserved2;
            uint16_t reserved3;
            union
            {
                int64_t llVal;
                int32_t lVal;
                uint8_t bVal;
                int16_t iVal;
                float fltVal;
                double dblVal;
                IL2CPP_VARIANT_BOOL boolVal;
                int32_t scode;
                int64_t cyVal;
                double date;
                Il2CppChar* bstrVal;
                Il2CppIUnknown* punkVal;
                void* pdispVal;
                Il2CppSafeArray* parray;
                uint8_t* pbVal;
                int16_t* piVal;
                int32_t* plVal;
                int64_t* pllVal;
                float* pfltVal;
                double* pdblVal;
                IL2CPP_VARIANT_BOOL* pboolVal;
                int32_t* pscode;
                int64_t* pcyVal;
                double* pdate;
                Il2CppChar* pbstrVal;
                Il2CppIUnknown** ppunkVal;
                void** ppdispVal;
                Il2CppSafeArray** pparray;
                struct Il2CppVariant* pvarVal;
                void* byref;
                char cVal;
                uint16_t uiVal;
                uint32_t ulVal;
                uint64_t ullVal;
                int intVal;
                unsigned int uintVal;
                Il2CppWin32Decimal* pdecVal;
                char* pcVal;
                uint16_t* puiVal;
                uint32_t* pulVal;
                uint64_t* pullVal;
                int* pintVal;
                unsigned int* puintVal;
                struct __tagBRECORD
                {
                    void* pvRecord;
                    void* pRecInfo;
                } n4;
            } n3;
        } n2;
        Il2CppWin32Decimal decVal;
    } n1;
} Il2CppVariant;
typedef struct Il2CppFileTime
{
    uint32_t low;
    uint32_t high;
} Il2CppFileTime;
typedef struct Il2CppStatStg
{
    Il2CppChar* name;
    uint32_t type;
    uint64_t size;
    Il2CppFileTime mtime;
    Il2CppFileTime ctime;
    Il2CppFileTime atime;
    uint32_t mode;
    uint32_t locks;
    Il2CppGuid clsid;
    uint32_t state;
    uint32_t reserved;
} Il2CppStatStg;
typedef enum Il2CppWindowsRuntimeTypeKind
{
    kTypeKindPrimitive = 0,
    kTypeKindMetadata,
    kTypeKindCustom
} Il2CppWindowsRuntimeTypeKind;
typedef struct Il2CppWindowsRuntimeTypeName
{
    Il2CppHString typeName;
    enum Il2CppWindowsRuntimeTypeKind typeKind;
} Il2CppWindowsRuntimeTypeName;
typedef void (*PInvokeMarshalToNativeFunc)(void* managedStructure, void* marshaledStructure);
typedef void (*PInvokeMarshalFromNativeFunc)(void* marshaledStructure, void* managedStructure);
typedef void (*PInvokeMarshalCleanupFunc)(void* marshaledStructure);
typedef struct Il2CppIUnknown* (*CreateCCWFunc)(Il2CppObject* obj);
typedef struct Il2CppInteropData
{
    Il2CppMethodPointer delegatePInvokeWrapperFunction;
    PInvokeMarshalToNativeFunc pinvokeMarshalToNativeFunction;
    PInvokeMarshalFromNativeFunc pinvokeMarshalFromNativeFunction;
    PInvokeMarshalCleanupFunc pinvokeMarshalCleanupFunction;
    CreateCCWFunc createCCWFunction;
    const Il2CppGuid* guid;
    const Il2CppType* type;
} Il2CppInteropData;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppGuid Il2CppGuid;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppAppDomainSetup Il2CppAppDomainSetup;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeDefinitionIndexHashTable Il2CppNameToTypeDefinitionIndexHashTable;
typedef struct Il2CppCodeGenModule Il2CppCodeGenModule;
typedef struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
} VirtualInvokeData;
typedef enum Il2CppTypeNameFormat
{
    IL2CPP_TYPE_NAME_FORMAT_IL,
    IL2CPP_TYPE_NAME_FORMAT_REFLECTION,
    IL2CPP_TYPE_NAME_FORMAT_FULL_NAME,
    IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} Il2CppTypeNameFormat;
typedef struct Il2CppDefaults
{
    Il2CppImage *corlib;
    Il2CppClass *object_class;
    Il2CppClass *byte_class;
    Il2CppClass *void_class;
    Il2CppClass *boolean_class;
    Il2CppClass *sbyte_class;
    Il2CppClass *int16_class;
    Il2CppClass *uint16_class;
    Il2CppClass *int32_class;
    Il2CppClass *uint32_class;
    Il2CppClass *int_class;
    Il2CppClass *uint_class;
    Il2CppClass *int64_class;
    Il2CppClass *uint64_class;
    Il2CppClass *single_class;
    Il2CppClass *double_class;
    Il2CppClass *char_class;
    Il2CppClass *string_class;
    Il2CppClass *enum_class;
    Il2CppClass *array_class;
    Il2CppClass *delegate_class;
    Il2CppClass *multicastdelegate_class;
    Il2CppClass *asyncresult_class;
    Il2CppClass *manualresetevent_class;
    Il2CppClass *typehandle_class;
    Il2CppClass *fieldhandle_class;
    Il2CppClass *methodhandle_class;
    Il2CppClass *systemtype_class;
    Il2CppClass *monotype_class;
    Il2CppClass *exception_class;
    Il2CppClass *threadabortexception_class;
    Il2CppClass *thread_class;
    Il2CppClass *internal_thread_class;
    Il2CppClass *appdomain_class;
    Il2CppClass *appdomain_setup_class;
    Il2CppClass *field_info_class;
    Il2CppClass *method_info_class;
    Il2CppClass *property_info_class;
    Il2CppClass *event_info_class;
    Il2CppClass *mono_event_info_class;
    Il2CppClass *stringbuilder_class;
    Il2CppClass *stack_frame_class;
    Il2CppClass *stack_trace_class;
    Il2CppClass *marshal_class;
    Il2CppClass *typed_reference_class;
    Il2CppClass *marshalbyrefobject_class;
    Il2CppClass *generic_ilist_class;
    Il2CppClass *generic_icollection_class;
    Il2CppClass *generic_ienumerable_class;
    Il2CppClass *generic_ireadonlylist_class;
    Il2CppClass *generic_ireadonlycollection_class;
    Il2CppClass *runtimetype_class;
    Il2CppClass *generic_nullable_class;
    Il2CppClass *il2cpp_com_object_class;
    Il2CppClass *attribute_class;
    Il2CppClass *customattribute_data_class;
    Il2CppClass *version;
    Il2CppClass *culture_info;
    Il2CppClass *async_call_class;
    Il2CppClass *assembly_class;
    Il2CppClass *mono_assembly_class;
    Il2CppClass *assembly_name_class;
    Il2CppClass *mono_field_class;
    Il2CppClass *mono_method_class;
    Il2CppClass *mono_method_info_class;
    Il2CppClass *mono_property_info_class;
    Il2CppClass *parameter_info_class;
    Il2CppClass *mono_parameter_info_class;
    Il2CppClass *module_class;
    Il2CppClass *pointer_class;
    Il2CppClass *system_exception_class;
    Il2CppClass *argument_exception_class;
    Il2CppClass *wait_handle_class;
    Il2CppClass *safe_handle_class;
    Il2CppClass *sort_key_class;
    Il2CppClass *dbnull_class;
    Il2CppClass *error_wrapper_class;
    Il2CppClass *missing_class;
    Il2CppClass *value_type_class;
    Il2CppClass *threadpool_wait_callback_class;
    MethodInfo *threadpool_perform_wait_callback_method;
    Il2CppClass *mono_method_message_class;
    Il2CppClass* ireference_class;
    Il2CppClass* ireferencearray_class;
    Il2CppClass* ikey_value_pair_class;
    Il2CppClass* key_value_pair_class;
    Il2CppClass* windows_foundation_uri_class;
    Il2CppClass* windows_foundation_iuri_runtime_class_class;
    Il2CppClass* system_uri_class;
    Il2CppClass* system_guid_class;
    Il2CppClass* sbyte_shared_enum;
    Il2CppClass* int16_shared_enum;
    Il2CppClass* int32_shared_enum;
    Il2CppClass* int64_shared_enum;
    Il2CppClass* byte_shared_enum;
    Il2CppClass* uint16_shared_enum;
    Il2CppClass* uint32_shared_enum;
    Il2CppClass* uint64_shared_enum;
} Il2CppDefaults;
extern Il2CppDefaults il2cpp_defaults;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct Il2CppObject Il2CppObject;
typedef struct MemberInfo MemberInfo;
typedef struct CustomAttributesCache
{
    int count;
    Il2CppObject** attributes;
} CustomAttributesCache;
typedef void (*CustomAttributesCacheGenerator)(CustomAttributesCache*);
typedef struct FieldInfo
{
    const char* name;
    const Il2CppType* type;
    Il2CppClass *parent;
    int32_t offset;
    uint32_t token;
} FieldInfo;
typedef struct PropertyInfo
{
    Il2CppClass *parent;
    const char *name;
    const MethodInfo *get;
    const MethodInfo *set;
    uint32_t attrs;
    uint32_t token;
} PropertyInfo;
typedef struct EventInfo
{
    const char* name;
    const Il2CppType* eventType;
    Il2CppClass* parent;
    const MethodInfo* add;
    const MethodInfo* remove;
    const MethodInfo* raise;
    uint32_t token;
} EventInfo;
typedef struct ParameterInfo
{
    const char* name;
    int32_t position;
    uint32_t token;
    const Il2CppType* parameter_type;
} ParameterInfo;
typedef void* (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**);
typedef enum MethodVariableKind
{
    kMethodVariableKind_This,
    kMethodVariableKind_Parameter,
    kMethodVariableKind_LocalVariable
} MethodVariableKind;
typedef enum SequencePointKind
{
    kSequencePointKind_Normal,
    kSequencePointKind_StepOut
} SequencePointKind;
typedef struct Il2CppMethodExecutionContextInfo
{
    TypeIndex typeIndex;
    int32_t nameIndex;
    int32_t scopeIndex;
} Il2CppMethodExecutionContextInfo;
typedef struct Il2CppMethodExecutionContextInfoIndex
{
    int32_t startIndex;
    int32_t count;
} Il2CppMethodExecutionContextInfoIndex;
typedef struct Il2CppMethodScope
{
    int32_t startOffset;
    int32_t endOffset;
} Il2CppMethodScope;
typedef struct Il2CppMethodHeaderInfo
{
    int32_t code_size;
    int32_t startScope;
    int32_t numScopes;
} Il2CppMethodHeaderInfo;
typedef struct Il2CppSequencePointSourceFile
{
    const char *file;
    uint8_t hash[16];
} Il2CppSequencePointSourceFile;
typedef struct Il2CppTypeSourceFilePair
{
    TypeDefinitionIndex klassIndex;
    int32_t sourceFileIndex;
} Il2CppTypeSourceFilePair;
typedef struct Il2CppSequencePoint
{
    MethodIndex methodDefinitionIndex;
    int32_t sourceFileIndex;
    int32_t lineStart, lineEnd;
    int32_t columnStart, columnEnd;
    int32_t ilOffset;
    SequencePointKind kind;
    int32_t isActive;
    int32_t id;
} Il2CppSequencePoint;
typedef struct Il2CppCatchPoint
{
    MethodIndex methodDefinitionIndex;
    TypeIndex catchTypeIndex;
    int32_t ilOffset;
    int32_t tryId;
    int32_t parentTryId;
} Il2CppCatchPoint;
typedef struct Il2CppDebuggerMetadataRegistration
{
    Il2CppMethodExecutionContextInfo* methodExecutionContextInfos;
    Il2CppMethodExecutionContextInfoIndex* methodExecutionContextInfoIndexes;
    Il2CppMethodScope* methodScopes;
    Il2CppMethodHeaderInfo* methodHeaderInfos;
    Il2CppSequencePointSourceFile* sequencePointSourceFiles;
    int32_t numSequencePoints;
    Il2CppSequencePoint* sequencePoints;
    int32_t numCatchPoints;
    Il2CppCatchPoint* catchPoints;
    int32_t numTypeSourceFileEntries;
    Il2CppTypeSourceFilePair* typeSourceFiles;
    const char** methodExecutionContextInfoStrings;
} Il2CppDebuggerMetadataRegistration;
typedef union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
} Il2CppRGCTXData;
typedef struct MethodInfo
{
    Il2CppMethodPointer methodPointer;
    InvokerMethod invoker_method;
    const char* name;
    Il2CppClass *klass;
    const Il2CppType *return_type;
    const ParameterInfo* parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const Il2CppMethodDefinition* methodDefinition;
    } Il2CppVariant;
    union
    {
        const Il2CppGenericMethod* genericMethod;
        const Il2CppGenericContainer* genericContainer;
    };
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t is_generic : 1;
    uint8_t is_inflated : 1;
    uint8_t wrapper_type : 1;
    uint8_t is_marshaled_from_native : 1;
} MethodInfo;
typedef struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;
typedef struct Il2CppClass
{
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass *generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    Il2CppClass* klass;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass** typeHierarchy;
    void *unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    __declspec(align(8)) size_t cctor_thread;
    GenericContainerIndex genericContainerIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t initialized_and_no_error : 1;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    uint8_t has_initialization_error : 1;
    VirtualInvokeData vtable[32];
} Il2CppClass;

typedef struct Il2CppClass_0 {
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass * generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    Il2CppClass* klass;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
} Il2CppClass_0;

typedef struct Il2CppClass_1 {
    struct Il2CppClass** typeHierarchy;
    void * unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
#ifdef IS_32BIT
    uint32_t cctor_thread;
#else
    __declspec(align(8)) size_t cctor_thread;
#endif
    GenericContainerIndex genericContainerIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t initialized_and_no_error : 1;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    uint8_t has_initialization_error : 1;
} Il2CppClass_1;

typedef struct __declspec(align(8)) Il2CppClass_Merged {
    struct Il2CppClass_0 _0;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass_1 _1;
    VirtualInvokeData vtable[32];
} Il2CppClass_Merged;

typedef struct Il2CppTypeDefinitionSizes
{
    uint32_t instance_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
} Il2CppTypeDefinitionSizes;
typedef struct Il2CppDomain
{
    Il2CppAppDomain* domain;
    Il2CppAppDomainSetup* setup;
    Il2CppAppContext* default_context;
    const char* friendly_name;
    uint32_t domain_id;
    volatile int threadpool_jobs;
    void* agent_info;
} Il2CppDomain;
typedef struct Il2CppAssemblyName
{
    const char* name;
    const char* culture;
    const uint8_t* public_key;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[8];
} Il2CppAssemblyName;
typedef struct Il2CppImage
{
    const char* name;
    const char *nameNoExt;
    Il2CppAssembly* assembly;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
    MethodIndex entryPointIndex;
    Il2CppNameToTypeDefinitionIndexHashTable * nameToClassHashTable;
    const Il2CppCodeGenModule* codeGenModule;
    uint32_t token;
    uint8_t dynamic;
} Il2CppImage;
typedef struct Il2CppAssembly
{
    Il2CppImage* image;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyName aname;
} Il2CppAssembly;
typedef struct Il2CppCodeGenOptions
{
    uint8_t enablePrimitiveValueTypeGenericSharing;
    int maximumRuntimeGenericDepth;
} Il2CppCodeGenOptions;
typedef struct Il2CppTokenIndexPair
{
    uint32_t token;
    int32_t index;
} Il2CppTokenIndexPair;
typedef struct Il2CppTokenRangePair
{
    uint32_t token;
    Il2CppRange range;
} Il2CppTokenRangePair;
typedef struct Il2CppTokenIndexMethodTuple
{
    uint32_t token;
    int32_t index;
    void** method;
    uint32_t genericMethodIndex;
} Il2CppTokenIndexMethodTuple;
typedef struct Il2CppTokenAdjustorThunkPair
{
    uint32_t token;
    Il2CppMethodPointer adjustorThunk;
} Il2CppTokenAdjustorThunkPair;
typedef struct Il2CppWindowsRuntimeFactoryTableEntry
{
    const Il2CppType* type;
    Il2CppMethodPointer createFactoryFunction;
} Il2CppWindowsRuntimeFactoryTableEntry;
typedef struct Il2CppCodeGenModule
{
    const char* moduleName;
    const uint32_t methodPointerCount;
    const Il2CppMethodPointer* methodPointers;
    const uint32_t adjustorThunkCount;
    const Il2CppTokenAdjustorThunkPair* adjustorThunks;
    const int32_t* invokerIndices;
    const uint32_t reversePInvokeWrapperCount;
    const Il2CppTokenIndexMethodTuple* reversePInvokeWrapperIndices;
    const uint32_t rgctxRangesCount;
    const Il2CppTokenRangePair* rgctxRanges;
    const uint32_t rgctxsCount;
    const Il2CppRGCTXDefinition* rgctxs;
    const Il2CppDebuggerMetadataRegistration *debuggerMetadata;
} Il2CppCodeGenModule;
typedef struct Il2CppCodeRegistration
{
    uint32_t reversePInvokeWrapperCount;
    const Il2CppMethodPointer* reversePInvokeWrappers;
    uint32_t genericMethodPointersCount;
    const Il2CppMethodPointer* genericMethodPointers;
    const Il2CppMethodPointer* genericAdjustorThunks;
    uint32_t invokerPointersCount;
    const InvokerMethod* invokerPointers;
    CustomAttributeIndex customAttributeCount;
    const CustomAttributesCacheGenerator* customAttributeGenerators;
    uint32_t unresolvedVirtualCallCount;
    const Il2CppMethodPointer* unresolvedVirtualCallPointers;
    uint32_t interopDataCount;
    Il2CppInteropData* interopData;
    uint32_t windowsRuntimeFactoryCount;
    Il2CppWindowsRuntimeFactoryTableEntry* windowsRuntimeFactoryTable;
    uint32_t codeGenModulesCount;
    const Il2CppCodeGenModule** codeGenModules;
} Il2CppCodeRegistration;
typedef struct Il2CppMetadataRegistration
{
    int32_t genericClassesCount;
    Il2CppGenericClass* const * genericClasses;
    int32_t genericInstsCount;
    const Il2CppGenericInst* const * genericInsts;
    int32_t genericMethodTableCount;
    const Il2CppGenericMethodFunctionsDefinitions* genericMethodTable;
    int32_t typesCount;
    const Il2CppType* const * types;
    int32_t methodSpecsCount;
    const Il2CppMethodSpec* methodSpecs;
    FieldIndex fieldOffsetsCount;
    const int32_t** fieldOffsets;
    TypeDefinitionIndex typeDefinitionsSizesCount;
    const Il2CppTypeDefinitionSizes** typeDefinitionsSizes;
    const size_t metadataUsagesCount;
    void** const* metadataUsages;
} Il2CppMetadataRegistration;
typedef struct Il2CppPerfCounters
{
    uint32_t jit_methods;
    uint32_t jit_bytes;
    uint32_t jit_time;
    uint32_t jit_failures;
    uint32_t exceptions_thrown;
    uint32_t exceptions_filters;
    uint32_t exceptions_finallys;
    uint32_t exceptions_depth;
    uint32_t aspnet_requests_queued;
    uint32_t aspnet_requests;
    uint32_t gc_collections0;
    uint32_t gc_collections1;
    uint32_t gc_collections2;
    uint32_t gc_promotions0;
    uint32_t gc_promotions1;
    uint32_t gc_promotion_finalizers;
    uint32_t gc_gen0size;
    uint32_t gc_gen1size;
    uint32_t gc_gen2size;
    uint32_t gc_lossize;
    uint32_t gc_fin_survivors;
    uint32_t gc_num_handles;
    uint32_t gc_allocated;
    uint32_t gc_induced;
    uint32_t gc_time;
    uint32_t gc_total_bytes;
    uint32_t gc_committed_bytes;
    uint32_t gc_reserved_bytes;
    uint32_t gc_num_pinned;
    uint32_t gc_sync_blocks;
    uint32_t remoting_calls;
    uint32_t remoting_channels;
    uint32_t remoting_proxies;
    uint32_t remoting_classes;
    uint32_t remoting_objects;
    uint32_t remoting_contexts;
    uint32_t loader_classes;
    uint32_t loader_total_classes;
    uint32_t loader_appdomains;
    uint32_t loader_total_appdomains;
    uint32_t loader_assemblies;
    uint32_t loader_total_assemblies;
    uint32_t loader_failures;
    uint32_t loader_bytes;
    uint32_t loader_appdomains_uloaded;
    uint32_t thread_contentions;
    uint32_t thread_queue_len;
    uint32_t thread_queue_max;
    uint32_t thread_num_logical;
    uint32_t thread_num_physical;
    uint32_t thread_cur_recognized;
    uint32_t thread_num_recognized;
    uint32_t interop_num_ccw;
    uint32_t interop_num_stubs;
    uint32_t interop_num_marshals;
    uint32_t security_num_checks;
    uint32_t security_num_link_checks;
    uint32_t security_time;
    uint32_t security_depth;
    uint32_t unused;
    uint64_t threadpool_workitems;
    uint64_t threadpool_ioworkitems;
    unsigned int threadpool_threads;
    unsigned int threadpool_iothreads;
} Il2CppPerfCounters;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct FieldInfo FieldInfo;
typedef struct EventInfo EventInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppAsyncCall Il2CppAsyncCall;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppWaitHandle Il2CppWaitHandle;
typedef struct MonitorData MonitorData;
typedef struct Il2CppReflectionAssembly Il2CppReflectionAssembly;
typedef Il2CppClass Il2CppVTable;
typedef struct Il2CppObject
{
    union
    {
        Il2CppClass *klass;
        Il2CppVTable *vtable;
    } Il2CppClass;
    MonitorData *monitor;
} Il2CppObject;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;
typedef struct Il2CppArray
{
    Il2CppObject obj;
    Il2CppArrayBounds *bounds;
    il2cpp_array_size_t max_length;
} Il2CppArray;
typedef struct Il2CppArraySize
{
    Il2CppObject obj;
    Il2CppArrayBounds *bounds;
    il2cpp_array_size_t max_length;
    __declspec(align(8)) void* vector[32];
} Il2CppArraySize;
typedef struct Il2CppString
{
    Il2CppObject object;
    int32_t length;
    Il2CppChar chars[32];
} Il2CppString;
typedef struct Il2CppReflectionType
{
    Il2CppObject object;
    const Il2CppType *type;
} Il2CppReflectionType;
typedef struct Il2CppReflectionRuntimeType
{
    Il2CppReflectionType type;
    Il2CppObject *type_info;
    Il2CppObject* genericCache;
    Il2CppObject* serializationCtor;
} Il2CppReflectionRuntimeType;
typedef struct Il2CppReflectionMonoType
{
    Il2CppReflectionRuntimeType type;
} Il2CppReflectionMonoType;
typedef struct Il2CppReflectionEvent
{
    Il2CppObject object;
    Il2CppObject *cached_add_event;
} Il2CppReflectionEvent;
typedef struct Il2CppReflectionMonoEvent
{
    Il2CppReflectionEvent event;
    Il2CppReflectionType* reflectedType;
    const EventInfo* eventInfo;
} Il2CppReflectionMonoEvent;
typedef struct Il2CppReflectionMonoEventInfo
{
    Il2CppReflectionType* declaringType;
    Il2CppReflectionType* reflectedType;
    Il2CppString* name;
    Il2CppReflectionMethod* addMethod;
    Il2CppReflectionMethod* removeMethod;
    Il2CppReflectionMethod* raiseMethod;
    uint32_t eventAttributes;
    Il2CppArray* otherMethods;
} Il2CppReflectionMonoEventInfo;
typedef struct Il2CppReflectionField
{
    Il2CppObject object;
    Il2CppClass *klass;
    FieldInfo *field;
    Il2CppString *name;
    Il2CppReflectionType *type;
    uint32_t attrs;
} Il2CppReflectionField;
typedef struct Il2CppReflectionProperty
{
    Il2CppObject object;
    Il2CppClass *klass;
    const PropertyInfo *property;
} Il2CppReflectionProperty;
typedef struct Il2CppReflectionMethod
{
    Il2CppObject object;
    const MethodInfo *method;
    Il2CppString *name;
    Il2CppReflectionType *reftype;
} Il2CppReflectionMethod;
typedef struct Il2CppReflectionGenericMethod
{
    Il2CppReflectionMethod base;
} Il2CppReflectionGenericMethod;
typedef struct Il2CppMethodInfo
{
    Il2CppReflectionType *parent;
    Il2CppReflectionType *ret;
    uint32_t attrs;
    uint32_t implattrs;
    uint32_t callconv;
} Il2CppMethodInfo;
typedef struct Il2CppPropertyInfo
{
    Il2CppReflectionType* parent;
    Il2CppReflectionType* declaringType;
    Il2CppString *name;
    Il2CppReflectionMethod *get;
    Il2CppReflectionMethod *set;
    uint32_t attrs;
} Il2CppPropertyInfo;
typedef struct Il2CppReflectionParameter
{
    Il2CppObject object;
    Il2CppReflectionType *ClassImpl;
    Il2CppObject *DefaultValueImpl;
    Il2CppObject *MemberImpl;
    Il2CppString *NameImpl;
    int32_t PositionImpl;
    uint32_t AttrsImpl;
    Il2CppObject *MarshalAsImpl;
} Il2CppReflectionParameter;
typedef struct Il2CppReflectionModule
{
    Il2CppObject obj;
    const Il2CppImage* image;
    Il2CppReflectionAssembly* assembly;
    Il2CppString* fqname;
    Il2CppString* name;
    Il2CppString* scopename;
    uint8_t is_resource;
    uint32_t token;
} Il2CppReflectionModule;
typedef struct Il2CppReflectionAssemblyName
{
    Il2CppObject obj;
    Il2CppString *name;
    Il2CppString *codebase;
    int32_t major, minor, build, revision;
    Il2CppObject *cultureInfo;
    uint32_t flags;
    uint32_t hashalg;
    Il2CppObject *keypair;
    Il2CppArray *publicKey;
    Il2CppArray *keyToken;
    uint32_t versioncompat;
    Il2CppObject *version;
    uint32_t processor_architecture;
    uint32_t contentType;
} Il2CppReflectionAssemblyName;
typedef struct Il2CppReflectionAssembly
{
    Il2CppObject object;
    const Il2CppAssembly *assembly;
    Il2CppObject *resolve_event_holder;
    Il2CppObject *evidence;
    Il2CppObject *minimum;
    Il2CppObject *optional;
    Il2CppObject *refuse;
    Il2CppObject *granted;
    Il2CppObject *denied;
    uint8_t from_byte_array;
    Il2CppString *name;
} Il2CppReflectionAssembly;
typedef struct Il2CppReflectionMarshal
{
    Il2CppObject object;
    int32_t count;
    int32_t type;
    int32_t eltype;
    Il2CppString* guid;
    Il2CppString* mcookie;
    Il2CppString* marshaltype;
    Il2CppObject* marshaltyperef;
    int32_t param_num;
    uint8_t has_size;
} Il2CppReflectionMarshal;
typedef struct Il2CppReflectionPointer
{
    Il2CppObject object;
    void* data;
    Il2CppReflectionType* type;
} Il2CppReflectionPointer;
typedef struct Il2CppInternalThread
{
    Il2CppObject obj;
    int lock_thread_id;
    void* handle;
    void* native_handle;
    Il2CppArray* cached_culture_info;
    Il2CppChar* name;
    int name_len;
    uint32_t state;
    Il2CppObject* abort_exc;
    int abort_state_handle;
    uint64_t tid;
    intptr_t debugger_thread;
    void** static_data;
    void* runtime_thread_info;
    Il2CppObject* current_appcontext;
    Il2CppObject* root_domain_thread;
    Il2CppArray* _serialized_principal;
    int _serialized_principal_version;
    void* appdomain_refs;
    int32_t interruption_requested;
    void* synch_cs;
    uint8_t threadpool_thread;
    uint8_t thread_interrupt_requested;
    int stack_size;
    uint8_t apartment_state;
    int critical_region_level;
    int managed_id;
    uint32_t small_id;
    void* manage_callback;
    void* interrupt_on_stop;
    intptr_t flags;
    void* thread_pinning_ref;
    void* abort_protected_block_count;
    int32_t priority;
    void* owned_mutexes;
    void * suspended;
    int32_t self_suspended;
    size_t thread_state;
    size_t unused2;
    void* last;
} Il2CppInternalThread;
typedef struct Il2CppIOSelectorJob
{
    Il2CppObject object;
    int32_t operation;
    Il2CppObject *callback;
    Il2CppObject *state;
} Il2CppIOSelectorJob;
typedef enum
{
    Il2Cpp_CallType_Sync = 0,
    Il2Cpp_CallType_BeginInvoke = 1,
    Il2Cpp_CallType_EndInvoke = 2,
    Il2Cpp_CallType_OneWay = 3
} Il2CppCallType;
typedef struct Il2CppMethodMessage
{
    Il2CppObject obj;
    Il2CppReflectionMethod *method;
    Il2CppArray *args;
    Il2CppArray *names;
    Il2CppArray *arg_types;
    Il2CppObject *ctx;
    Il2CppObject *rval;
    Il2CppObject *exc;
    Il2CppAsyncResult *async_result;
    uint32_t call_type;
} Il2CppMethodMessage;
typedef struct Il2CppAppDomainSetup
{
    Il2CppObject object;
    Il2CppString* application_base;
    Il2CppString* application_name;
    Il2CppString* cache_path;
    Il2CppString* configuration_file;
    Il2CppString* dynamic_base;
    Il2CppString* license_file;
    Il2CppString* private_bin_path;
    Il2CppString* private_bin_path_probe;
    Il2CppString* shadow_copy_directories;
    Il2CppString* shadow_copy_files;
    uint8_t publisher_policy;
    uint8_t path_changed;
    int loader_optimization;
    uint8_t disallow_binding_redirects;
    uint8_t disallow_code_downloads;
    Il2CppObject* activation_arguments;
    Il2CppObject* domain_initializer;
    Il2CppObject* application_trust;
    Il2CppArray* domain_initializer_args;
    uint8_t disallow_appbase_probe;
    Il2CppArray* configuration_bytes;
    Il2CppArray* serialized_non_primitives;
} Il2CppAppDomainSetup;
typedef struct Il2CppThread
{
    Il2CppObject obj;
    Il2CppInternalThread* internal_thread;
    Il2CppObject* start_obj;
    Il2CppException* pending_exception;
    Il2CppObject* principal;
    int32_t principal_version;
    Il2CppDelegate* delegate;
    Il2CppObject* executionContext;
    uint8_t executionContextBelongsToOuterScope;
} Il2CppThread;
typedef struct Il2CppException
{
    Il2CppObject object;
    Il2CppString* className;
    Il2CppString* message;
    Il2CppObject* _data;
    Il2CppException* inner_ex;
    Il2CppString* _helpURL;
    Il2CppArray* trace_ips;
    Il2CppString* stack_trace;
    Il2CppString* remote_stack_trace;
    int remote_stack_index;
    Il2CppObject* _dynamicMethods;
    il2cpp_hresult_t hresult;
    Il2CppString* source;
    Il2CppObject* safeSerializationManager;
    Il2CppArray* captured_traces;
    Il2CppArray* native_trace_ips;
} Il2CppException;
typedef struct Il2CppSystemException
{
    Il2CppException base;
} Il2CppSystemException;
typedef struct Il2CppArgumentException
{
    Il2CppException base;
    Il2CppString *argName;
} Il2CppArgumentException;
typedef struct Il2CppTypedRef
{
    const Il2CppType *type;
    void* value;
    Il2CppClass *klass;
} Il2CppTypedRef;
typedef struct Il2CppDelegate
{
    Il2CppObject object;
    Il2CppMethodPointer method_ptr;
    InvokerMethod invoke_impl;
    Il2CppObject *target;
    const MethodInfo *method;
    void* delegate_trampoline;
    intptr_t extraArg;
    uint8_t **method_code;
    Il2CppReflectionMethod *method_info;
    Il2CppReflectionMethod *original_method_info;
    Il2CppObject *data;
    uint8_t method_is_virtual;
} Il2CppDelegate;
typedef struct Il2CppMulticastDelegate
{
    Il2CppDelegate delegate;
    Il2CppArray *delegates;
} Il2CppMulticastDelegate;
typedef struct Il2CppMarshalByRefObject
{
    Il2CppObject obj;
    Il2CppObject *identity;
} Il2CppMarshalByRefObject;
typedef struct Il2CppAppDomain
{
    Il2CppMarshalByRefObject mbr;
    Il2CppDomain *data;
} Il2CppAppDomain;
typedef struct Il2CppStackFrame
{
    Il2CppObject obj;
    int32_t il_offset;
    int32_t native_offset;
    uint64_t methodAddress;
    uint32_t methodIndex;
    Il2CppReflectionMethod *method;
    Il2CppString *filename;
    int32_t line;
    int32_t column;
    Il2CppString *internal_method_name;
} Il2CppStackFrame;
typedef struct Il2CppDateTimeFormatInfo
{
    Il2CppObject obj;
    Il2CppObject* CultureData;
    Il2CppString* Name;
    Il2CppString* LangName;
    Il2CppObject* CompareInfo;
    Il2CppObject* CultureInfo;
    Il2CppString* AMDesignator;
    Il2CppString* PMDesignator;
    Il2CppString* DateSeparator;
    Il2CppString* GeneralShortTimePattern;
    Il2CppString* GeneralLongTimePattern;
    Il2CppString* TimeSeparator;
    Il2CppString* MonthDayPattern;
    Il2CppString* DateTimeOffsetPattern;
    Il2CppObject* Calendar;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
    Il2CppString* FullDateTimePattern;
    Il2CppArray* AbbreviatedDayNames;
    Il2CppArray* ShortDayNames;
    Il2CppArray* DayNames;
    Il2CppArray* AbbreviatedMonthNames;
    Il2CppArray* MonthNames;
    Il2CppArray* GenitiveMonthNames;
    Il2CppArray* GenitiveAbbreviatedMonthNames;
    Il2CppArray* LeapYearMonthNames;
    Il2CppString* LongDatePattern;
    Il2CppString* ShortDatePattern;
    Il2CppString* YearMonthPattern;
    Il2CppString* LongTimePattern;
    Il2CppString* ShortTimePattern;
    Il2CppArray* YearMonthPatterns;
    Il2CppArray* ShortDatePatterns;
    Il2CppArray* LongDatePatterns;
    Il2CppArray* ShortTimePatterns;
    Il2CppArray* LongTimePatterns;
    Il2CppArray* EraNames;
    Il2CppArray* AbbrevEraNames;
    Il2CppArray* AbbrevEnglishEraNames;
    Il2CppArray* OptionalCalendars;
    uint8_t readOnly;
    int32_t FormatFlags;
    int32_t CultureID;
    uint8_t UseUserOverride;
    uint8_t UseCalendarInfo;
    int32_t DataItem;
    uint8_t IsDefaultCalendar;
    Il2CppArray* DateWords;
    Il2CppString* FullTimeSpanPositivePattern;
    Il2CppString* FullTimeSpanNegativePattern;
    Il2CppArray* dtfiTokenHash;
} Il2CppDateTimeFormatInfo;
typedef struct Il2CppNumberFormatInfo
{
    Il2CppObject obj;
    Il2CppArray* numberGroupSizes;
    Il2CppArray* currencyGroupSizes;
    Il2CppArray* percentGroupSizes;
    Il2CppString* positiveSign;
    Il2CppString* negativeSign;
    Il2CppString* numberDecimalSeparator;
    Il2CppString* numberGroupSeparator;
    Il2CppString* currencyGroupSeparator;
    Il2CppString* currencyDecimalSeparator;
    Il2CppString* currencySymbol;
    Il2CppString* ansiCurrencySymbol;
    Il2CppString* naNSymbol;
    Il2CppString* positiveInfinitySymbol;
    Il2CppString* negativeInfinitySymbol;
    Il2CppString* percentDecimalSeparator;
    Il2CppString* percentGroupSeparator;
    Il2CppString* percentSymbol;
    Il2CppString* perMilleSymbol;
    Il2CppArray* nativeDigits;
    int dataItem;
    int numberDecimalDigits;
    int currencyDecimalDigits;
    int currencyPositivePattern;
    int currencyNegativePattern;
    int numberNegativePattern;
    int percentPositivePattern;
    int percentNegativePattern;
    int percentDecimalDigits;
    int digitSubstitution;
    uint8_t readOnly;
    uint8_t useUserOverride;
    uint8_t isInvariant;
    uint8_t validForParseAsNumber;
    uint8_t validForParseAsCurrency;
} Il2CppNumberFormatInfo;
typedef struct Il2CppCultureData
{
    Il2CppObject obj;
    Il2CppString *AMDesignator;
    Il2CppString *PMDesignator;
    Il2CppString *TimeSeparator;
    Il2CppArray *LongTimePatterns;
    Il2CppArray *ShortTimePatterns;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
} Il2CppCultureData;
typedef struct Il2CppCalendarData
{
    Il2CppObject obj;
    Il2CppString *NativeName;
    Il2CppArray *ShortDatePatterns;
    Il2CppArray *YearMonthPatterns;
    Il2CppArray *LongDatePatterns;
    Il2CppString *MonthDayPattern;
    Il2CppArray *EraNames;
    Il2CppArray *AbbreviatedEraNames;
    Il2CppArray *AbbreviatedEnglishEraNames;
    Il2CppArray *DayNames;
    Il2CppArray *AbbreviatedDayNames;
    Il2CppArray *SuperShortDayNames;
    Il2CppArray *MonthNames;
    Il2CppArray *AbbreviatedMonthNames;
    Il2CppArray *GenitiveMonthNames;
    Il2CppArray *GenitiveAbbreviatedMonthNames;
} Il2CppCalendarData;
typedef struct Il2CppCultureInfo
{
    Il2CppObject obj;
    uint8_t is_read_only;
    int32_t lcid;
    int32_t parent_lcid;
    int32_t datetime_index;
    int32_t number_index;
    int32_t default_calendar_type;
    uint8_t use_user_override;
    Il2CppNumberFormatInfo* number_format;
    Il2CppDateTimeFormatInfo* datetime_format;
    Il2CppObject* textinfo;
    Il2CppString* name;
    Il2CppString* englishname;
    Il2CppString* nativename;
    Il2CppString* iso3lang;
    Il2CppString* iso2lang;
    Il2CppString* win3lang;
    Il2CppString* territory;
    Il2CppArray* native_calendar_names;
    Il2CppString* compareinfo;
    const void* text_info_data;
    int dataItem;
    Il2CppObject* calendar;
    Il2CppObject* parent_culture;
    uint8_t constructed;
    Il2CppArray* cached_serialized_form;
    Il2CppObject* cultureData;
    uint8_t isInherited;
} Il2CppCultureInfo;
typedef struct Il2CppRegionInfo
{
    Il2CppObject obj;
    int32_t geo_id;
    Il2CppString* iso2name;
    Il2CppString* iso3name;
    Il2CppString* win3name;
    Il2CppString* english_name;
    Il2CppString* native_name;
    Il2CppString* currency_symbol;
    Il2CppString* iso_currency_symbol;
    Il2CppString* currency_english_name;
    Il2CppString* currency_native_name;
} Il2CppRegionInfo;
typedef struct Il2CppSafeHandle
{
    Il2CppObject base;
    void* handle;
    int state;
    uint8_t owns_handle;
    uint8_t fullyInitialized;
} Il2CppSafeHandle;
typedef struct Il2CppStringBuilder Il2CppStringBuilder;
typedef struct Il2CppStringBuilder
{
    Il2CppObject object;
    Il2CppArray* chunkChars;
    Il2CppStringBuilder* chunkPrevious;
    int chunkLength;
    int chunkOffset;
    int maxCapacity;
} Il2CppStringBuilder;
typedef struct Il2CppSocketAddress
{
    Il2CppObject base;
    int m_Size;
    Il2CppArray* data;
    uint8_t m_changed;
    int m_hash;
} Il2CppSocketAddress;
typedef struct Il2CppSortKey
{
    Il2CppObject base;
    Il2CppString *str;
    Il2CppArray *key;
    int32_t options;
    int32_t lcid;
} Il2CppSortKey;
typedef struct Il2CppErrorWrapper
{
    Il2CppObject base;
    int32_t errorCode;
} Il2CppErrorWrapper;
typedef struct Il2CppAsyncResult
{
    Il2CppObject base;
    Il2CppObject *async_state;
    Il2CppWaitHandle *handle;
    Il2CppDelegate *async_delegate;
    void* data;
    Il2CppAsyncCall *object_data;
    uint8_t sync_completed;
    uint8_t completed;
    uint8_t endinvoke_called;
    Il2CppObject *async_callback;
    Il2CppObject *execution_context;
    Il2CppObject *original_context;
} Il2CppAsyncResult;
typedef struct Il2CppAsyncCall
{
    Il2CppObject base;
    Il2CppMethodMessage *msg;
    MethodInfo *cb_method;
    Il2CppDelegate *cb_target;
    Il2CppObject *state;
    Il2CppObject *res;
    Il2CppArray *out_args;
} Il2CppAsyncCall;
typedef struct Il2CppExceptionWrapper Il2CppExceptionWrapper;
typedef struct Il2CppExceptionWrapper
{
    Il2CppException* ex;
} Il2CppExceptionWrapper;
typedef struct Il2CppIOAsyncResult
{
    Il2CppObject base;
    Il2CppDelegate* callback;
    Il2CppObject* state;
    Il2CppWaitHandle* wait_handle;
    uint8_t completed_synchronously;
    uint8_t completed;
} Il2CppIOAsyncResult;
typedef struct Il2CppSocketAsyncResult
{
    Il2CppIOAsyncResult base;
    Il2CppObject* socket;
    int32_t operation;
    Il2CppException* delayedException;
    Il2CppObject* endPoint;
    Il2CppArray* buffer;
    int32_t offset;
    int32_t size;
    int32_t socket_flags;
    Il2CppObject* acceptSocket;
    Il2CppArray* addresses;
    int32_t port;
    Il2CppObject* buffers;
    uint8_t reuseSocket;
    int32_t currentAddress;
    Il2CppObject* acceptedSocket;
    int32_t total;
    int32_t error;
    int32_t endCalled;
} Il2CppSocketAsyncResult;
typedef enum Il2CppResourceLocation
{
    IL2CPP_RESOURCE_LOCATION_EMBEDDED = 1,
    IL2CPP_RESOURCE_LOCATION_ANOTHER_ASSEMBLY = 2,
    IL2CPP_RESOURCE_LOCATION_IN_MANIFEST = 4
} Il2CppResourceLocation;
typedef struct Il2CppManifestResourceInfo
{
    Il2CppObject object;
    Il2CppReflectionAssembly* assembly;
    Il2CppString* filename;
    uint32_t location;
} Il2CppManifestResourceInfo;
typedef struct Il2CppAppContext
{
    Il2CppObject obj;
    int32_t domain_id;
    int32_t context_id;
    void* static_data;
} Il2CppAppContext;
typedef struct Il2CppDecimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } u;
        uint16_t signscale;
    } u;
    uint32_t Hi32;
    union
    {
        struct
        {
            uint32_t Lo32;
            uint32_t Mid32;
        } v;
        uint64_t Lo64;
    } v;
} Il2CppDecimal;
typedef struct Il2CppDouble
{
    uint32_t mantLo : 32;
    uint32_t mantHi : 20;
    uint32_t exp : 11;
    uint32_t sign : 1;
} Il2CppDouble;
typedef union Il2CppDouble_double
{
    Il2CppDouble s;
    double d;
} Il2CppDouble_double;
typedef enum Il2CppDecimalCompareResult
{
    IL2CPP_DECIMAL_CMP_LT = -1,
    IL2CPP_DECIMAL_CMP_EQ,
    IL2CPP_DECIMAL_CMP_GT
} Il2CppDecimalCompareResult;
typedef struct Il2CppSingle
{
    uint32_t mant : 23;
    uint32_t exp : 8;
    uint32_t sign : 1;
} Il2CppSingle;
typedef union Il2CppSingle_float
{
    Il2CppSingle s;
    float f;
} Il2CppSingle_float;

#pragma warning(disable : 4369)
#pragma warning(disable : 4309)
#pragma warning(disable : 4359)
#if !defined(_GHIDRA_) && !defined(_IDA_)
namespace app {
#endif

    // ******************************************************************************
    // * Application types from method calls
    // ******************************************************************************

    struct Object__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct Object__StaticFields {
    };

    struct Object__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Object__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Object__VTable vtable;
    };

    struct Type__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetCustomAttributes;
        VirtualInvokeData GetCustomAttributes_1;
        VirtualInvokeData IsDefined;
        VirtualInvokeData get_DeclaringType;
        VirtualInvokeData get_MemberType;
        VirtualInvokeData __unknown;
        VirtualInvokeData get_ReflectedType;
        VirtualInvokeData __unknown_1;
        VirtualInvokeData __unknown_2;
        VirtualInvokeData __unknown_3;
        VirtualInvokeData __unknown_4;
        VirtualInvokeData get_MetadataToken;
        VirtualInvokeData __unknown_5;
        VirtualInvokeData __unknown_6;
        VirtualInvokeData get_Attributes;
        VirtualInvokeData __unknown_7;
        VirtualInvokeData __unknown_8;
        VirtualInvokeData __unknown_9;
        VirtualInvokeData get_HasElementType;
        VirtualInvokeData get_IsAbstract;
        VirtualInvokeData get_IsArray;
        VirtualInvokeData get_IsByRef;
        VirtualInvokeData get_IsClass;
        VirtualInvokeData get_IsContextful;
        VirtualInvokeData get_IsEnum;
        VirtualInvokeData get_IsExplicitLayout;
        VirtualInvokeData get_IsInterface;
        VirtualInvokeData get_IsMarshalByRef;
        VirtualInvokeData get_IsNestedPublic;
        VirtualInvokeData get_IsPointer;
        VirtualInvokeData get_IsPrimitive;
        VirtualInvokeData get_IsPublic;
        VirtualInvokeData get_IsSealed;
        VirtualInvokeData get_IsSerializable;
        VirtualInvokeData get_IsValueType;
        VirtualInvokeData __unknown_10;
        VirtualInvokeData get_TypeHandle;
        VirtualInvokeData __unknown_11;
        VirtualInvokeData Equals_1;
        VirtualInvokeData GetType;
        VirtualInvokeData IsSubclassOf;
        VirtualInvokeData GetInterfaceMap;
        VirtualInvokeData __unknown_12;
        VirtualInvokeData IsAssignableFrom;
        VirtualInvokeData IsInstanceOfType;
        VirtualInvokeData GetArrayRank;
        VirtualInvokeData __unknown_13;
        VirtualInvokeData GetEvent;
        VirtualInvokeData __unknown_14;
        VirtualInvokeData __unknown_15;
        VirtualInvokeData GetField;
        VirtualInvokeData __unknown_16;
        VirtualInvokeData GetFields;
        VirtualInvokeData __unknown_17;
        VirtualInvokeData GetMember;
        VirtualInvokeData GetMember_1;
        VirtualInvokeData GetMember_2;
        VirtualInvokeData __unknown_18;
        VirtualInvokeData GetMethod;
        VirtualInvokeData GetMethod_1;
        VirtualInvokeData GetMethod_2;
        VirtualInvokeData GetMethod_3;
        VirtualInvokeData GetMethod_4;
        VirtualInvokeData __unknown_19;
        VirtualInvokeData GetMethods;
        VirtualInvokeData __unknown_20;
        VirtualInvokeData __unknown_21;
        VirtualInvokeData GetProperties;
        VirtualInvokeData __unknown_22;
        VirtualInvokeData GetProperty;
        VirtualInvokeData GetProperty_1;
        VirtualInvokeData GetProperty_2;
        VirtualInvokeData GetProperty_3;
        VirtualInvokeData GetProperty_4;
        VirtualInvokeData __unknown_23;
        VirtualInvokeData __unknown_24;
        VirtualInvokeData __unknown_25;
        VirtualInvokeData __unknown_26;
        VirtualInvokeData __unknown_27;
        VirtualInvokeData __unknown_28;
        VirtualInvokeData __unknown_29;
        VirtualInvokeData __unknown_30;
        VirtualInvokeData IsValueTypeImpl;
        VirtualInvokeData IsContextfulImpl;
        VirtualInvokeData IsMarshalByRefImpl;
        VirtualInvokeData GetConstructor;
        VirtualInvokeData GetConstructor_1;
        VirtualInvokeData GetConstructor_2;
        VirtualInvokeData GetConstructors;
        VirtualInvokeData __unknown_31;
        VirtualInvokeData FindMembers;
        VirtualInvokeData InvokeMember;
        VirtualInvokeData __unknown_32;
        VirtualInvokeData GetGenericArguments;
        VirtualInvokeData get_ContainsGenericParameters;
        VirtualInvokeData get_IsGenericTypeDefinition;
        VirtualInvokeData GetGenericTypeDefinition;
        VirtualInvokeData get_IsGenericType;
        VirtualInvokeData MakeGenericType;
        VirtualInvokeData get_IsGenericParameter;
        VirtualInvokeData GetGenericParameterConstraints;
        VirtualInvokeData MakeByRefType;
    };

    struct Type__StaticFields {
        uint16_t Delimiter;
        struct Type__Array* EmptyTypes;
        struct MemberFilter* FilterAttribute;
        struct MemberFilter* FilterName;
        struct MemberFilter* FilterNameIgnoreCase;
        struct Object* Missing;
    };

    struct Type__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Type__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Type__VTable vtable;
    };

    struct Object {
        struct Object__Class* klass;
        MonitorData* monitor;
    };

    struct RuntimeTypeHandle__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetObjectData;
    };

    struct RuntimeTypeHandle__StaticFields {
    };

    struct RuntimeTypeHandle__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct RuntimeTypeHandle__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct RuntimeTypeHandle__VTable vtable;
    };

    struct Char__Array__VTable {
    };

    struct Char__Array__StaticFields {
    };

    struct Char__Array__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Char__Array__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Char__Array__VTable vtable;
    };

    struct __declspec(align(8)) Encoding__Fields {
        int32_t codePage;
        int32_t windows_code_page;
        bool is_readonly;
        struct DecoderFallback* decoder_fallback;
        struct EncoderFallback* encoder_fallback;
        struct String* body_name;
        struct String* encoding_name;
        struct String* header_name;
        bool is_mail_news_display;
        bool is_mail_news_save;
        bool is_browser_save;
        bool is_browser_display;
        struct String* web_name;
    };

    struct Encoding__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Clone;
        VirtualInvokeData __unknown;
        VirtualInvokeData GetByteCount;
        VirtualInvokeData GetByteCount_1;
        VirtualInvokeData __unknown_1;
        VirtualInvokeData GetBytes;
        VirtualInvokeData GetBytes_1;
        VirtualInvokeData GetBytes_2;
        VirtualInvokeData GetBytes_3;
        VirtualInvokeData __unknown_2;
        VirtualInvokeData __unknown_3;
        VirtualInvokeData GetChars;
        VirtualInvokeData GetChars_1;
        VirtualInvokeData GetDecoder;
        VirtualInvokeData Clone_1;
        VirtualInvokeData __unknown_4;
        VirtualInvokeData __unknown_5;
        VirtualInvokeData GetPreamble;
        VirtualInvokeData GetString;
        VirtualInvokeData GetString_1;
        VirtualInvokeData get_HeaderName;
        VirtualInvokeData get_WebName;
        VirtualInvokeData GetByteCount_2;
        VirtualInvokeData GetBytes_4;
    };

    struct Encoding__StaticFields {
        struct Assembly* i18nAssembly;
        bool i18nDisabled;
        struct EncodingInfo__Array* encoding_infos;
        struct Object__Array* encodings;
        struct Encoding* asciiEncoding;
        struct Encoding* bigEndianEncoding;
        struct Encoding* defaultEncoding;
        struct Encoding* utf7Encoding;
        struct Encoding* utf8EncodingWithMarkers;
        struct Encoding* utf8EncodingWithoutMarkers;
        struct Encoding* unicodeEncoding;
        struct Encoding* isoLatin1Encoding;
        struct Encoding* utf8EncodingUnsafe;
        struct Encoding* utf32Encoding;
        struct Encoding* bigEndianUTF32Encoding;
        struct Object* lockobj;
    };

    struct Encoding {
        struct Encoding__Class* klass;
        MonitorData* monitor;
        struct Encoding__Fields fields;
    };

    struct Encoding__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Encoding__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Encoding__VTable vtable;
    };

    struct Char__Array {
        struct Char__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint16_t vector[32];
    };

    struct RuntimeTypeHandle {
        void* value;
    };

    struct RuntimeTypeHandle__Boxed {
        struct RuntimeTypeHandle__Class* klass;
        MonitorData* monitor;
        struct RuntimeTypeHandle fields;
    };



    struct __declspec(align(8)) Type__Fields {
        struct RuntimeTypeHandle _impl;
    };

    struct Type {
        struct Type__Class* klass;
        MonitorData* monitor;
        struct Type__Fields fields;
    };

    struct String__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetTypeCode;
        VirtualInvokeData System_IConvertible_ToBoolean;
        VirtualInvokeData System_IConvertible_ToByte;
        VirtualInvokeData System_IConvertible_ToChar;
        VirtualInvokeData System_IConvertible_ToDateTime;
        VirtualInvokeData System_IConvertible_ToDecimal;
        VirtualInvokeData System_IConvertible_ToDouble;
        VirtualInvokeData System_IConvertible_ToInt16;
        VirtualInvokeData System_IConvertible_ToInt32;
        VirtualInvokeData System_IConvertible_ToInt64;
        VirtualInvokeData System_IConvertible_ToSByte;
        VirtualInvokeData System_IConvertible_ToSingle;
        VirtualInvokeData ToString_1;
        VirtualInvokeData System_IConvertible_ToType;
        VirtualInvokeData System_IConvertible_ToUInt16;
        VirtualInvokeData System_IConvertible_ToUInt32;
        VirtualInvokeData System_IConvertible_ToUInt64;
        VirtualInvokeData CompareTo;
        VirtualInvokeData System_Collections_IEnumerable_GetEnumerator;
        VirtualInvokeData Clone;
        VirtualInvokeData CompareTo_1;
        VirtualInvokeData Equals_1;
        VirtualInvokeData System_Collections_Generic_IEnumerable_char__GetEnumerator;
    };

    struct String__StaticFields {
        struct String* Empty;
        struct Char__Array* WhiteChars;
    };

    struct String__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct String__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct String__VTable vtable;
    };

    struct __declspec(align(8)) String__Fields {
        int32_t length;
        uint16_t start_char;
    };

    struct String {
        struct String__Class* klass;
        MonitorData* monitor;
        struct String__Fields fields;
    };

    struct IFormatProvider {
        struct IFormatProvider__Class* klass;
        MonitorData* monitor;
    };

    struct IFormatProvider__VTable {
        VirtualInvokeData GetFormat;
    };

    struct IFormatProvider__StaticFields {
    };

    struct IFormatProvider__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct IFormatProvider__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct IFormatProvider__VTable vtable;
    };

    struct Byte__Array__VTable {
    };

    struct Byte__Array__StaticFields {
    };

    struct Byte__Array__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Byte__Array__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Byte__Array__VTable vtable;
    };

    struct Byte__Array {
        struct Byte__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint8_t vector[32];
    };

    struct __declspec(align(8)) LuaBaseManager__Fields {
        struct LuaEnv* _luaenv;
    };

    struct LuaManager_ILuaReload__VTable {
        VirtualInvokeData Reload;
        VirtualInvokeData GetHotfixFuncs;
    };

    struct LuaManager_ILuaReload__StaticFields {
    };

    struct LuaManager_ILuaReload__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct LuaManager_ILuaReload__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct LuaManager_ILuaReload__VTable vtable;
    };

    struct LuaBaseManager__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Init;
        VirtualInvokeData Tick;
        VirtualInvokeData PostTick;
        VirtualInvokeData LateTick;
        VirtualInvokeData LatePreTick;
        VirtualInvokeData LatePreTickEnd;
        VirtualInvokeData LatePostTick;
        VirtualInvokeData LatePostTickEnd;
        VirtualInvokeData Dump;
        VirtualInvokeData Destroy;
        VirtualInvokeData ClearOnLevelDestroy;
        VirtualInvokeData InitOnConnect;
        VirtualInvokeData ClearOnDisconnect;
        VirtualInvokeData ClearOnBackHome;
        VirtualInvokeData ReloadRes;
        VirtualInvokeData InitByLocalData;
        VirtualInvokeData InitLua;
        VirtualInvokeData Require;
        VirtualInvokeData OnLoadLuaFinish;
    };

    struct LuaBaseManager__StaticFields {
        struct DelegateBridge* _c__Hotfix0_ctor;
        struct DelegateBridge* __Hotfix0_Init;
        struct DelegateBridge* __Hotfix0_InitLua;
        struct DelegateBridge* __Hotfix0_DoLua;
        struct DelegateBridge* __Hotfix0_Require;
        struct DelegateBridge* __Hotfix0_OnLoadLuaFinish;
        struct DelegateBridge* __Hotfix0_ReloadRes;
        struct DelegateBridge* __Hotfix0_Tick;
        struct DelegateBridge* __Hotfix0_Destroy;
        struct DelegateBridge* __Hotfix0_ClearOnLevelDestroy;
        struct DelegateBridge* __Hotfix0_WaitForSeconds;
        struct DelegateBridge* __Hotfix0_WaitForSecondsImp;
        struct DelegateBridge* __Hotfix0_WaitForSeveralFrames;
        struct DelegateBridge* __Hotfix0_WaitForSeveralFramesImp;
        struct DelegateBridge* __Hotfix0_WaitForEndOfFrame;
        struct DelegateBridge* __Hotfix0_WaitForEndOfFrameImp;
        struct DelegateBridge* __Hotfix0_WaitForFixedUpdate;
        struct DelegateBridge* __Hotfix0_WaitForFixedUpdateImp;
        struct DelegateBridge* __Hotfix0_IsIOS;
        struct DelegateBridge* __Hotfix0_IsAndroid;
        struct DelegateBridge* __Hotfix0_ModifySafeFloat;
        struct DelegateBridge* __Hotfix0_ModifySafeInt;
        struct DelegateBridge* __Hotfix0_ModifySafeBool;
        struct DelegateBridge* __Hotfix0_GetActorPlugin;
        struct DelegateBridge* __Hotfix0_GetNetPacketV1Data;
        struct DelegateBridge* __Hotfix0_CreateLuaTable;
        struct DelegateBridge* __Hotfix0_ConvertDictionaryToLuaTable;
        struct DelegateBridge* __Hotfix0_ConvertDictionaryKeysToList;
        struct DelegateBridge* __Hotfix0_CreateLuaDelegate;
        struct DelegateBridge* __Hotfix0_CreateLuaAction;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithOneArg;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithThreeArgs;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithFourArgs;
        struct DelegateBridge* __Hotfix0_CreateDelegate;
        struct DelegateBridge* __Hotfix0_CreateAction;
        struct DelegateBridge* __Hotfix0_CreateActionWithOneArg;
        struct DelegateBridge* __Hotfix0_CreateActionWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateActionWithMultiArgs;
        struct DelegateBridge* __Hotfix0_CreateStaticClassDelegate;
        struct DelegateBridge* __Hotfix0_CreateStaticClassAction;
        struct DelegateBridge* __Hotfix0_CreateStaticClassActionWithOneArg;
        struct DelegateBridge* __Hotfix0_CreateStaticClassActionWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateStaticClassActionWithMultiArgs;
        struct DelegateBridge* __Hotfix0_CreateInstance;
        struct DelegateBridge* __Hotfix0_CreateGenericInstance;
        struct DelegateBridge* __Hotfix0_CreateGenericInstanceWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateGenericInstanceWithMultiArgs;
        struct DelegateBridge* __Hotfix0_GetObjectField;
        struct DelegateBridge* __Hotfix0_GetObjectFieldValue;
        struct DelegateBridge* __Hotfix0_SetObjectFieldValue;
        struct DelegateBridge* __Hotfix0_GetStaticClassField;
        struct DelegateBridge* __Hotfix0_GetStaticClassFieldValue;
        struct DelegateBridge* __Hotfix0_SetStaticClassFieldValue;
        struct DelegateBridge* __Hotfix0_InvokeObjectMethod;
        struct DelegateBridge* __Hotfix0_InvokeObjectMethodWithMultiArgs;
        struct DelegateBridge* __Hotfix0_InvokeStaticClassMethod;
        struct DelegateBridge* __Hotfix0_InvokeStaticClassMethodWithMultiArgs;
        struct DelegateBridge* __Hotfix0_ConvertLuaArgToCSharpArg;
        struct DelegateBridge* __Hotfix0_ChangeType;
        struct DelegateBridge* __Hotfix1_ChangeType;
        struct DelegateBridge* __Hotfix0_GetClassType;
        struct DelegateBridge* __Hotfix1_GetClassType;
        struct DelegateBridge* __Hotfix0_GetTypeArray;
        struct DelegateBridge* __Hotfix1_GetTypeArray;
        struct DelegateBridge* __Hotfix2_GetTypeArray;
        struct DelegateBridge* __Hotfix3_GetTypeArray;
        struct DelegateBridge* __Hotfix0_InvokeMethodImp;
        struct DelegateBridge* __Hotfix1_InvokeMethodImp;
    };

    struct LuaBaseManager__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct LuaBaseManager__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct LuaBaseManager__VTable vtable;
    };

    struct LuaBaseManager {
        struct LuaBaseManager__Class* klass;
        MonitorData* monitor;
        struct LuaBaseManager__Fields fields;
    };

    struct LuaManager_ILuaReload {
        struct LuaManager_ILuaReload__Class* klass;
        MonitorData* monitor;
    };

    struct LuaManager_ILuaHotFix {
        struct LuaManager_ILuaHotFix__Class* klass;
        MonitorData* monitor;
    };

    struct LuaManager_ILuaMain {
        struct LuaManager_ILuaMain__Class* klass;
        MonitorData* monitor;
    };

    struct LuaManager__Fields {
        struct LuaBaseManager__Fields _;
        struct LuaManager_ILuaReload* _luaReload;
        struct LuaManager_ILuaHotFix* _luaHotfix;
        struct LuaManager_ILuaMain* _luaMain;
        struct ActorManager_ILuaActorManager* _luaActorMgr;
        struct Action* reloadCallback;
        struct LuaEnv_CustomLoader* _customLoader;
        uint32_t _gcCnt;
        bool gcEnabled;
        bool _isStarted;
        bool _hotfixInited;
        struct LuaTable* _patchTable;
    };

    struct LuaManager {
        struct LuaManager__Class* klass;
        MonitorData* monitor;
        struct LuaManager__Fields fields;
    };


    enum class DateTimeKind__Enum : int32_t {
        Unspecified = 0x00000000,
        Utc = 0x00000001,
        Local = 0x00000002,
    };

    struct TimeSpan {
        int64_t _ticks;
    };

    struct DateTime {
        struct TimeSpan ticks;
        DateTimeKind__Enum kind;
    };

    struct DateTime__Boxed {
        struct DateTime__Class* klass;
        MonitorData* monitor;
        struct DateTime fields;
    };

    struct __declspec(align(8)) LuaBase__Fields {
        bool disposed;
        int32_t luaReference;
        void* luaEnv;
    };

    struct DelegateBridgeBase__Fields {
        struct LuaBase__Fields _;
        void* firstKey;
        void* firstValue;
        void* bindTo;
        int32_t errorFuncRef;
    };


    struct DelegateBridge__Fields {
        struct DelegateBridgeBase__Fields _;
        int32_t _oldTop;
        void* _stack;
    };

    struct DelegateBridge {
        void* klass;
        MonitorData* monitor;
        struct DelegateBridge__Fields fields;
    };

    struct MMLHJDIKHGO__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct MMLHJDIKHGO__StaticFields {
        struct DelegateBridge* FBPNECEFLOE;
        struct DelegateBridge* PHCOGNGOLIB;
        struct DelegateBridge* OMMFGIEPLNB;
        struct DelegateBridge* DNGLBOAIJHH;
        struct DelegateBridge* NCLIEEPFHDL;
        struct DelegateBridge* KKOMKIEGPDO;
        struct DelegateBridge* FKBGMOOHCEA;
        struct DelegateBridge* DLBNKFCNNPF;
        struct DelegateBridge* ENEPELNLPFO;
        struct DelegateBridge* MPAKCCMDCIJ;
        struct DelegateBridge* OPGPJFEHPHA;
        struct DelegateBridge* KJEDMNINANM;
        struct DelegateBridge* EKCDCMOHEII;
        struct DelegateBridge* DGOPGFKLHCK;
        struct DelegateBridge* GNFJCLOPBJA;
        struct DelegateBridge* ECOIAFKEILB;
        struct DelegateBridge* BMONDEPLGNK;
        struct DelegateBridge* EODKGEBKPEI;
        struct DelegateBridge* IGGNFLOEKIA;
        struct DelegateBridge* FGKFHJNKCKN;
        struct DelegateBridge* JCAEBEECFNM;
        struct DelegateBridge* NDEKDPHIEMI;
        struct DelegateBridge* DMGCMECPIAF;
        struct DelegateBridge* FMLKIDOAAGM;
    };

    struct MMLHJDIKHGO__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct MMLHJDIKHGO__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct MMLHJDIKHGO__VTable vtable;
    };

    enum class MMLHJDIKHGO_PJOIODIAPNK__Enum : int32_t {
        UDP = 0x00000000,
        TCP = 0x00000001,
    };

    struct MMLHJDIKHGO_PJOIODIAPNK__Enum__Boxed {
        struct MMLHJDIKHGO_PJOIODIAPNK__Enum__Class* klass;
        MonitorData* monitor;
        MMLHJDIKHGO_PJOIODIAPNK__Enum value;
    };

    struct __declspec(align(8)) MMLHJDIKHGO__Fields {
        void* MEOGCAMBLHJ;
        MMLHJDIKHGO_PJOIODIAPNK__Enum JAAAEGMMPIF;
    };

    struct MMLHJDIKHGO {
        struct MMLHJDIKHGO__Class* klass;
        MonitorData* monitor;
        struct MMLHJDIKHGO__Fields fields;
    };

    struct ConfigChannel__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct ConfigChannel__StaticFields {
        struct DelegateBridge* _c__Hotfix0_ctor;
        struct DelegateBridge* __Hotfix0_IsOversea;
        struct DelegateBridge* __Hotfix0_IsPreGMPackage;
        struct DelegateBridge* __Hotfix0_IsRelPackage;
    };

    struct ConfigChannel__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct ConfigChannel__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct ConfigChannel__VTable vtable;
    };

    enum class AccountBranches__Enum : int32_t {
        Original = 0x00000000,
        UC = 0x00000001,
        QIHOO = 0x00000002,
        OPPO = 0x00000003,
        VIVO = 0x00000004,
        HUAWEI = 0x00000005,
        XIAOMI = 0x00000006,
        TENCENT = 0x00000007,
        GIONEE = 0x00000008,
        LENOVO = 0x00000009,
        BAIDU = 0x0000000a,
        COOLPAD = 0x0000000b,
        WANDOUJIA = 0x0000000c,
        MEIZU = 0x0000000d,
        BILIBILI = 0x0000000e,
        LESHI = 0x0000000f,
        JAPAN = 0x00000010,
        TAIWAN = 0x00000011,
        KOREA = 0x00000012,
        OVERSEAS = 0x00000013,
        GLOBAL = 0x00000014,
    };

    enum class PaymentBranches__Enum : int32_t {
        DEFAULT = 0x00000000,
        APPSTORE_CN = 0x00000001,
        ORIGINAL_ANDROID_PAY = 0x00000002,
        GOOGLE_ANDROID_PAY = 0x00000003,
    };

    struct __declspec(align(8)) ConfigChannel__Fields {
        struct String* ChannelName;
        struct String* BundleIdentifier;
        struct String* PS4ClientID;
        struct String* PS5ClientID;
        struct String* ProductName;
        struct String* PreDefines;
        struct String* TimeZones;
        void* DispatchConfigs;
        int32_t VersionCode;
        bool Obb;
        bool DataUseAssetBundle;
        bool EventUseAssetBundle;
        bool BetaMark;
        struct String* CVDefault;
        struct String* FAQUrl;
        struct String* ExceptionReportUrl;
        struct String* NetworkErrReportUrl;
        struct String* MediumReportUrl;
        struct String* CrashReportUrl;
        struct String* LogRecorderUrl;
        AccountBranches__Enum AccountBranch;
        PaymentBranches__Enum PaymentBranch;
        struct String* GVoiceAppID;
        struct String* GVoiceAppKey;
        struct String* GVoiceServerInfo;
        struct String* BaseTextLang;
        struct String* BaseAudioLang;
    };

    struct ConfigChannel {
        struct ConfigChannel__Class* klass;
        MonitorData* monitor;
        struct ConfigChannel__Fields fields;
    };

    struct UInt16__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint16_t vector[32];
    };

    struct IPAddress__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct IPAddress__StaticFields {
        struct IPAddress* Any;
        struct IPAddress* Broadcast;
        struct IPAddress* Loopback;
        struct IPAddress* None;
        struct IPAddress* IPv6Any;
        struct IPAddress* IPv6Loopback;
        struct IPAddress* IPv6None;
    };

    struct IPAddress__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct IPAddress__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct IPAddress__VTable vtable;
    };

    enum class AddressFamily__Enum : int32_t {
        Unknown = -1,
        Unspecified = 0x00000000,
        Unix = 0x00000001,
        InterNetwork = 0x00000002,
        ImpLink = 0x00000003,
        Pup = 0x00000004,
        Chaos = 0x00000005,
        NS = 0x00000006,
        Ipx = 0x00000006,
        Iso = 0x00000007,
        Osi = 0x00000007,
        Ecma = 0x00000008,
        DataKit = 0x00000009,
        Ccitt = 0x0000000a,
        Sna = 0x0000000b,
        DecNet = 0x0000000c,
        DataLink = 0x0000000d,
        Lat = 0x0000000e,
        HyperChannel = 0x0000000f,
        AppleTalk = 0x00000010,
        NetBios = 0x00000011,
        VoiceView = 0x00000012,
        FireFox = 0x00000013,
        Banyan = 0x00000015,
        Atm = 0x00000016,
        InterNetworkV6 = 0x00000017,
        Cluster = 0x00000018,
        Ieee12844 = 0x00000019,
        Irda = 0x0000001a,
        NetworkDesigners = 0x0000001c,
        Max = 0x0000001d,
    };

    struct __declspec(align(8)) IPAddress__Fields {
        int64_t m_Address;
        AddressFamily__Enum m_Family;
        struct UInt16__Array* m_Numbers;
        int64_t m_ScopeId;
        int32_t m_HashCode;
    };

    struct IPAddress {
        struct IPAddress__Class* klass;
        MonitorData* monitor;
        struct IPAddress__Fields fields;
    };

    struct GameLogin__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Init;
        VirtualInvokeData Tick;
        VirtualInvokeData PostTick;
        VirtualInvokeData LateTick;
        VirtualInvokeData LatePreTick;
        VirtualInvokeData LatePreTickEnd;
        VirtualInvokeData LatePostTick;
        VirtualInvokeData LatePostTickEnd;
        VirtualInvokeData Dump;
        VirtualInvokeData Destroy;
        VirtualInvokeData ClearOnLevelDestroy;
        VirtualInvokeData InitOnConnect;
        VirtualInvokeData ClearOnDisconnect;
        VirtualInvokeData ClearOnBackHome;
        VirtualInvokeData ReloadRes;
        VirtualInvokeData InitByLocalData;
        VirtualInvokeData OnNotify;
    };

    struct GameLogin__StaticFields {
        float MLDLNMIPKPC;
        struct Action_1_Boolean_* CILACBNHEJJ;
        struct Action_1_Boolean_* CMLLGAMAOGJ;
        struct Action_1_Boolean_* KLCMHGNLIDA;
        struct Action_1_Boolean_* KHCJGGHLPJB;
        struct DelegateBridge* FBPNECEFLOE;
        struct DelegateBridge* DJGJOAIGMLD;
        struct DelegateBridge* GHBMOCNLBEP;
        struct DelegateBridge* HAOJOAIJDLC;
        struct DelegateBridge* BNPHMIAKMLH;
        struct DelegateBridge* POHLKBNMAKN;
        struct DelegateBridge* ACKIAAPPOCM;
        struct DelegateBridge* NGBIKKCFAMM;
        struct DelegateBridge* INCKMHOGFFM;
        struct DelegateBridge* NCKBEMGGAFG;
        struct DelegateBridge* LBBMGIBJGKK;
        struct DelegateBridge* BGCCHJCOMCA;
        struct DelegateBridge* IGGNFLOEKIA;
        struct DelegateBridge* FGKFHJNKCKN;
        struct DelegateBridge* NDEKDPHIEMI;
        struct DelegateBridge* DMGCMECPIAF;
        struct DelegateBridge* OPIAFCKIIMH;
        struct DelegateBridge* MCMBGKDLJDP;
        struct DelegateBridge* PKKEJMCEFMN;
        struct DelegateBridge* CKFHNMFEGDH;
        struct DelegateBridge* ENDBLDDKOJM;
        struct DelegateBridge* AJIAHCGPFAM;
        struct DelegateBridge* MJFEOEEDIOM;
        struct DelegateBridge* ADLFHGAEGGP;
        struct DelegateBridge* BDDLFNOHNPL;
        struct DelegateBridge* DHPBOABCJCA;
        struct DelegateBridge* FGLFGLOCDAI;
        struct DelegateBridge* EBCBEEKJDAG;
        struct DelegateBridge* PGDPLBMLIOB;
        struct DelegateBridge* BIDFGAAMEIF;
        struct DelegateBridge* OJKLMMNGCCE;
        struct DelegateBridge* JLEKLKBLABP;
        struct DelegateBridge* AGGGLDBEDFC;
        struct DelegateBridge* DNGLBOAIJHH;
        struct DelegateBridge* GNFJCLOPBJA;
        struct DelegateBridge* DPBNGBNHHKM;
        struct DelegateBridge* FOLCPIBPFHC;
        struct DelegateBridge* IIFHAOOAAAN;
        struct DelegateBridge* FNODFDBIEGF;
        struct DelegateBridge* BMLDOAJDEJN;
        struct DelegateBridge* PAIMJJBFPOE;
        struct DelegateBridge* EEFPHGIJLFA;
        struct DelegateBridge* ENJJEODKEDM;
        struct DelegateBridge* NCLIEEPFHDL;
        struct DelegateBridge* ICIBJOEFHIB;
        struct DelegateBridge* PGELDOHIPEO;
        struct DelegateBridge* LNKHMBAGMPM;
        struct DelegateBridge* BMOFMEKMKKB;
        struct DelegateBridge* FMBPAMABPAN;
        struct DelegateBridge* JOIDODGIKPF;
        struct DelegateBridge* HKCBNNKMBLK;
        struct DelegateBridge* AJKLPKIBLFO;
        struct DelegateBridge* IEHIFOMCEMC;
        struct DelegateBridge* MNFIFFECNIB;
        struct DelegateBridge* PDACKOLBBAD;
        struct DelegateBridge* NOOBGJMNHHK;
        struct DelegateBridge* NNNBPLNLFJA;
        struct DelegateBridge* CNIBMCFKIGE;
        struct DelegateBridge* MOKNHGMODIF;
        struct DelegateBridge* DJGADCOHAHL;
        struct DelegateBridge* ANBGMAFNKBM;
        struct DelegateBridge* KLEBJFCFALN;
        struct DelegateBridge* FACBONJJDGK;
        struct DelegateBridge* GCAOJPKPHBI;
        struct DelegateBridge* LNJDKPPGIHI;
        struct DelegateBridge* LHJKPKHDFBJ;
        struct DelegateBridge* ONLNGOLFEGA;
        struct DelegateBridge* MPEPFPBGPED;
        struct DelegateBridge* EOLNJIBIOOI;
        struct DelegateBridge* HIKIICODOHG;
        struct DelegateBridge* HFNFADFGFNL;
        struct DelegateBridge* BEDLIIGCPPB;
        struct DelegateBridge* BOGFANIJHNG;
        struct DelegateBridge* JCMMIJINFHM;
        struct DelegateBridge* PIBDEAPDMCN;
        struct DelegateBridge* HHOHNDMOIDG;
        struct DelegateBridge* OJPHGKMIPFO;
        struct DelegateBridge* LCCJIFBKFGP;
        struct DelegateBridge* KLCMEPIDAFN;
        struct DelegateBridge* EPICONADDGN;
        struct DelegateBridge* FIADEEKPMIN;
        struct DelegateBridge* AMLNCFFHMMH;
        struct DelegateBridge* BGBACPBFBJA;
        struct DelegateBridge* FPFJEGLIGKF;
        struct DelegateBridge* NEBMEFPPFHM;
        struct DelegateBridge* CDCALMACEIP;
        struct DelegateBridge* IGNFNPLNEBA;
        struct DelegateBridge* OJBBNCGKILF;
        struct DelegateBridge* FLNMAACDBHM;
        struct DelegateBridge* HMNCCPODJGF;
        struct DelegateBridge* CGGCJLLEENH;
        struct DelegateBridge* LHJKHFBCIDE;
        struct DelegateBridge* PDMFMEFDHMP;
        struct DelegateBridge* MBMHIBGNIKC;
        struct DelegateBridge* KFNKKPLIIKF;
        struct DelegateBridge* EPLNCJFPCNG;
        struct DelegateBridge* CKDMDIFBFMO;
        struct DelegateBridge* APKIONCDHNO;
        struct DelegateBridge* GLBKPNPOPLF;
        struct DelegateBridge* JNOMMDNINDF;
        struct DelegateBridge* JNBKEEAIEGD;
        struct DelegateBridge* PJGIPHAPLHJ;
        struct DelegateBridge* EFCAJLBLGHG;
        struct DelegateBridge* IMDDIJKJBFJ;
        struct DelegateBridge* IDLKNOKFEEG;
        struct DelegateBridge* CIPKGBECGCO;
        struct DelegateBridge* GLOOBCCHAAO;
        struct DelegateBridge* KMNLELOIKCA;
        struct DelegateBridge* GDHONGOIBHA;
        struct DelegateBridge* FKIGDKPILPF;
        struct DelegateBridge* EDOBLDBKOBI;
        struct DelegateBridge* NGEPNKNJCON;
        struct DelegateBridge* CCAAIBGMMJJ;
        struct DelegateBridge* FMFMJABGOPO;
        struct DelegateBridge* MANGFJHPNFG;
        struct DelegateBridge* BHHNILKLEOB;
        struct DelegateBridge* JACGFJLFOPN;
        struct DelegateBridge* OLDOMPNPJKD;
        struct DelegateBridge* OAOLKAIKNEO;
        struct DelegateBridge* IFLMKHFDPEN;
        struct DelegateBridge* DEJIGJPCNJL;
        struct DelegateBridge* BDEDCJFGFMB;
        struct DelegateBridge* AKGNLGBKMJH;
        struct DelegateBridge* LIDLNAGEELP;
        struct DelegateBridge* HDMNGHAJLKO;
        struct DelegateBridge* OHPMGIJHACJ;
        struct DelegateBridge* JLJJNOEPOOP;
        struct DelegateBridge* HDDALELIOOB;
        struct DelegateBridge* HFNDDDAPAHM;
        struct DelegateBridge* OLFOHKMOMLE;
        struct DelegateBridge* FPNDMIOONDK;
        struct DelegateBridge* KBCBMIBDPCE;
        struct DelegateBridge* DJOJBKNPCNM;
        struct DelegateBridge* NIJAAMDNELA;
        struct DelegateBridge* NINDPFAFIDN;
        struct DelegateBridge* NEKKIGGEEEE;
        struct DelegateBridge* EAMDPBHJOOH;
        struct DelegateBridge* LHMKOMMHCNJ;
        struct DelegateBridge* NBOOIECOMOL;
        struct DelegateBridge* BJHLCNJMGCO;
        struct DelegateBridge* PIOBJAHPLBJ;
        struct DelegateBridge* DKPBBLPHGKA;
        struct DelegateBridge* HKCIKDAPFDF;
        struct DelegateBridge* GAJAKCFJFFG;
        struct DelegateBridge* CFJMPGGFPFO;
    };

    struct NetworkManager_1__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct GameLogin__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct GameLogin__VTable vtable;
    };

    struct __declspec(align(8)) NetworkManager_1__Fields {
        struct MMLHJDIKHGO* _client;
        bool useJobThread;
        struct ConfigChannel* channelConfig;
        void* _DispatchSeverData_k__BackingField;
        void* serverPatterns;
        void* currentServerConfig;
        bool _isGlobalDispatch_k__BackingField;
        bool ServerStop;
        bool HasServerList;
        struct IPAddress* _lastIPAddress_k__BackingField;
        struct IPAddress* lastDispatchIP;
        struct String* lastIP;
        uint16_t lastPort;
        bool isConnect;
        bool isValidToSend;
        struct DateTime _nextPingTime;
        struct DateTime _nextCheckConnectTime;
        int32_t _watch;
        uint32_t _clientSequenceId;
        void* trafficMonitor;
        void* reason2Reconnect;
        void* reason2Callback;
        bool hasDisconnectCB;
        uint32_t resultData;
        uint32_t GOGAODGGJJB;
        void* _packetQueue;
        struct DateTime _nextPrintTime;
        void* _regionBlackList;
        float FNOLDKFPBLL;
        float PJHHBBICHPD;
        void* _pingAllRegionAddressCoroutine;
        void* _allAddressPingCoroutines;
        bool isPingAllRegionAddressDone;
        int32_t _runningPingCount;
        bool isReconnect;
        uint32_t timeoutCount;
        int32_t _reconnectCorotine;
        void* coroutine_1;
        void* _packetCount;
        void* _specialPacketDeserializedCallback;
    };

    struct MoleMole_NetworkManager {
        struct NetworkManager_1__Class* klass;
        MonitorData* monitor;
        struct NetworkManager_1__Fields fields;
    };

    struct __declspec(align(8)) MessageBase_1__Fields {
        int32_t count;
        uint8_t _flag;
        int32_t JABMLLBAOLE;
    };

    struct GKOJAICIOPA__Fields {
        struct MessageBase_1__Fields _;
        struct String* string_1;
        struct String* string_2;
        struct String* string_3;
        struct String* string_4;
        struct String* string_5;
        uint32_t DCDMCEEGPHO;
        uint64_t HNNPGFOOOGF;
        bool GJEGPDCKHKC;
        uint32_t OHILLNPMGOG;
        uint32_t PJCAONOLKME;
        struct String* string_6;
        struct String* string_7;
        struct String* string_8;
        uint32_t GLALNAFJNPI;
        bool GFDJDACPNEF;
        uint32_t HGMCFPBHFIP;
        uint32_t MHOMEBNKBMB;
        struct String* string_16;
        struct String* string_9;
        uint32_t IJKANMFMBID;
        void* CJDKDCIPBPF;
        void* EOIAHBHLOOP;
        struct String* string_10;
        uint32_t LIDAFJHHONJ;
        uint32_t PMGDOOKBJND;
        struct String* string_11;
        uint32_t NFNAILJKHNB;
        void* HBMOHKNKCDH;
        struct String* string_12;
        uint32_t BEAOKGHFDLP;
        struct NHHMPCAAKGF* COALKJGFLEJ;
        uint32_t NDJHCJFIKGH;
        struct String* string_13;
        struct String* string_14;
        bool OKOOABLDFNB;
        uint32_t FCOKNAHMKMD;
        uint32_t KOHNHBDBAGH;
        void* HAJNHPHHBJH;
        struct String* string_15;
    };

    struct GKOJAICIOPA {
        void* klass;
        MonitorData* monitor;
        struct GKOJAICIOPA__Fields fields;
    };

    struct Array__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetEnumerator;
        VirtualInvokeData Clone;
        VirtualInvokeData System_Collections_ICollection_get_Count;
        VirtualInvokeData get_IsSynchronized;
        VirtualInvokeData get_SyncRoot;
        VirtualInvokeData CopyTo;
        VirtualInvokeData get_IsFixedSize;
        VirtualInvokeData get_IsReadOnly;
        VirtualInvokeData System_Collections_IList_get_Item;
        VirtualInvokeData System_Collections_IList_set_Item;
        VirtualInvokeData System_Collections_IList_Add;
        VirtualInvokeData System_Collections_IList_Clear;
        VirtualInvokeData System_Collections_IList_Contains;
        VirtualInvokeData System_Collections_IList_IndexOf;
        VirtualInvokeData System_Collections_IList_Insert;
        VirtualInvokeData System_Collections_IList_Remove;
        VirtualInvokeData System_Collections_IList_RemoveAt;
    };

    struct Array__StaticFields {
    };

    struct Array__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Array__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Array__VTable vtable;
    };

    struct Array {
        struct Array__Class* klass;
        MonitorData* monitor;
    };

    struct Byte__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData ToString_1;
        VirtualInvokeData GetTypeCode;
        VirtualInvokeData System_IConvertible_ToBoolean;
        VirtualInvokeData System_IConvertible_ToByte;
        VirtualInvokeData System_IConvertible_ToChar;
        VirtualInvokeData System_IConvertible_ToDateTime;
        VirtualInvokeData System_IConvertible_ToDecimal;
        VirtualInvokeData System_IConvertible_ToDouble;
        VirtualInvokeData System_IConvertible_ToInt16;
        VirtualInvokeData System_IConvertible_ToInt32;
        VirtualInvokeData System_IConvertible_ToInt64;
        VirtualInvokeData System_IConvertible_ToSByte;
        VirtualInvokeData System_IConvertible_ToSingle;
        VirtualInvokeData ToString_2;
        VirtualInvokeData System_IConvertible_ToType;
        VirtualInvokeData System_IConvertible_ToUInt16;
        VirtualInvokeData System_IConvertible_ToUInt32;
        VirtualInvokeData System_IConvertible_ToUInt64;
        VirtualInvokeData CompareTo;
        VirtualInvokeData CompareTo_1;
        VirtualInvokeData Equals_1;
    };

    struct Byte__StaticFields {
    };

    struct Byte__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Byte__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Byte__VTable vtable;
    };

    struct Vector3 {
        float x;
        float y;
        float z;
    };

    struct Vector3d {
        double x;
        double y;
        double z;
    };

    struct Vector3d_1 {
        double x;
        double y;
        double z;
    };

    struct LuaAbilityParam__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct LuaAbilityParam__StaticFields {
        struct DelegateBridge* _c__Hotfix0_ctor;
        struct DelegateBridge* __Hotfix0_Init;
    };

    struct LuaAbilityParam__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct LuaAbilityParam__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct LuaAbilityParam__VTable vtable;
    };

    struct __declspec(align(8)) LuaAbilityParam__Fields {
        int32_t valueInt;
        float valueFloat;
        struct String* valueString;
    };

    struct LuaAbilityParam {
        struct LuaAbilityParam__Class* klass;
        MonitorData* monitor;
        struct LuaAbilityParam__Fields fields;
    };

    struct __declspec(align(8)) LuaLogic__Fields {
        void* OnInit;
        void* OnTick;
        void* OnDestroy;
    };

    struct ILuaActor__VTable {
        VirtualInvokeData get_alias;
        VirtualInvokeData get_isAutoStart;
        VirtualInvokeData get_uActor;
        VirtualInvokeData InvokeOnInteraction;
        VirtualInvokeData InvokeOnResetFreeStyle;
        VirtualInvokeData InvokeOnAbility;
        VirtualInvokeData InvokeOnFinalTalkFinish;
        VirtualInvokeData InvokeOnAppear;
        VirtualInvokeData InvokeOnDisappear;
    };

    struct ILuaActor__StaticFields {
    };

    struct ILuaActor__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct ILuaActor__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct ILuaActor__VTable vtable;
    };

    struct ILuaActor {
        struct ILuaActor__Class* klass;
        MonitorData* monitor;
    };

    struct ActorManager__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Init;
        VirtualInvokeData Tick;
        VirtualInvokeData PostTick;
        VirtualInvokeData LateTick;
        VirtualInvokeData LatePreTick;
        VirtualInvokeData LatePreTickEnd;
        VirtualInvokeData LatePostTick;
        VirtualInvokeData LatePostTickEnd;
        VirtualInvokeData Dump;
        VirtualInvokeData Destroy;
        VirtualInvokeData ClearOnLevelDestroy;
        VirtualInvokeData InitOnConnect;
        VirtualInvokeData ClearOnDisconnect;
        VirtualInvokeData ClearOnBackHome;
        VirtualInvokeData ReloadRes;
        VirtualInvokeData InitByLocalData;
    };

    struct ActorManager__StaticFields {
        struct DelegateBridge* _c__Hotfix0_ctor;
        struct DelegateBridge* __Hotfix0_GetTaskListByTaskId;
        struct DelegateBridge* __Hotfix0_AddTaskByTaskId;
        struct DelegateBridge* __Hotfix0_RemoveTaskByTaskId;
        struct DelegateBridge* __Hotfix0_FinishTaskByTaskId;
        struct DelegateBridge* __Hotfix0_FinishAndClearAllTaskByType;
        struct DelegateBridge* __Hotfix0_GetTransByAlias;
        struct DelegateBridge* __Hotfix0_AddTransByAlias;
        struct DelegateBridge* __Hotfix0_RemoveTransByAlias;
        struct DelegateBridge* __Hotfix0_GetActor;
        struct DelegateBridge* __Hotfix1_GetActor;
        struct DelegateBridge* __Hotfix0_GetQuestActor;
        struct DelegateBridge* __Hotfix0_ReloadRes;
        struct DelegateBridge* __Hotfix0_AddActor;
        struct DelegateBridge* __Hotfix0_AddQuestActor;
        struct DelegateBridge* __Hotfix0_RemoveActor;
        struct DelegateBridge* __Hotfix0_ChangeActorAlias;
        struct DelegateBridge* __Hotfix0_RemoveQuestActor;
        struct DelegateBridge* __Hotfix0_DestroyByAlias;
        struct DelegateBridge* __Hotfix0_Init;
        struct DelegateBridge* __Hotfix0_InjectLuaActorMgr;
        struct DelegateBridge* __Hotfix0_Tick;
        struct DelegateBridge* __Hotfix0_TickActor;
        struct DelegateBridge* __Hotfix0_FireEvent;
        struct DelegateBridge* __Hotfix0_DispatchEvent;
        struct DelegateBridge* __Hotfix0_Destroy;
        struct DelegateBridge* __Hotfix0_DestroyOnDisconnect;
        struct DelegateBridge* __Hotfix0_DestroyBeforeQuestListInit;
        struct DelegateBridge* __Hotfix0_ClearSoft;
        struct DelegateBridge* __Hotfix0_Clear;
        struct DelegateBridge* __Hotfix0_InitLuaGlobal;
        struct DelegateBridge* __Hotfix0_InitLuaSubGlobal;
        struct DelegateBridge* __Hotfix0_PostInitLuaGlobal;
        struct DelegateBridge* __Hotfix0_PostEnterSceneLuaGlobal;
        struct DelegateBridge* __Hotfix0_LocalEntityRewind;
        struct DelegateBridge* __Hotfix0_RefreshCommonInfoData;
        struct DelegateBridge* __Hotfix0_ReconnectInitLuaGlobal;
        struct DelegateBridge* __Hotfix0_CreateActor;
        struct DelegateBridge* __Hotfix0_CreateActorWithInfo;
        struct DelegateBridge* __Hotfix0_CreateLocalActorWithInfo;
        struct DelegateBridge* __Hotfix0_CreateActorWithLocalInfo;
        struct DelegateBridge* __Hotfix0_CreateQuestActor;
        struct DelegateBridge* __Hotfix0_CreateCutsceneActor;
        struct DelegateBridge* __Hotfix0_CreateGadgetActor;
        struct DelegateBridge* __Hotfix0_CreateInterActor;
        struct DelegateBridge* __Hotfix0_StartActor;
        struct DelegateBridge* __Hotfix0_DestroyActor;
        struct DelegateBridge* __Hotfix0_DestroyActorMeta;
        struct DelegateBridge* __Hotfix0_SetEntityHandler;
        struct DelegateBridge* __Hotfix0_GetEntityHandler;
        struct DelegateBridge* __Hotfix0_DestroyEntityHandler;
        struct DelegateBridge* __Hotfix0_NotifyBanDailyExternal;
        struct DelegateBridge* __Hotfix0_NotifyStartDailyExternal;
        struct DelegateBridge* __Hotfix0_ClearOnLevelDestroy;
        struct DelegateBridge* __Hotfix0_ClearOnDisconnect;
        struct DelegateBridge* __Hotfix0_ClearOnBackHome;
        struct DelegateBridge* __Hotfix0_ClearBeforeQuestListInit;
        struct DelegateBridge* __Hotfix0_CreateLocalMonster;
        struct DelegateBridge* __Hotfix0_CreateLocalGadget;
        struct DelegateBridge* __Hotfix0_GetTaskTagsByAction;
        struct DelegateBridge* __Hotfix0_InitTaskTag;
        struct DelegateBridge* __Hotfix0_PlayerDie;
        struct DelegateBridge* __Hotfix0_PlayerInCombat;
        struct DelegateBridge* __Hotfix0_OpenMainPage;
        struct DelegateBridge* __Hotfix0_OpenPage;
        struct DelegateBridge* __Hotfix0_Transmiting;
        struct DelegateBridge* __Hotfix0_EnterDungeon;
        struct DelegateBridge* __Hotfix0_PauseByTag;
        struct DelegateBridge* __Hotfix0_ResumeByTag;
        struct DelegateBridge* __Hotfix0_AddPauseTag;
        struct DelegateBridge* __Hotfix0_RemovePauseTag;
        struct DelegateBridge* __Hotfix0_ClearPauseTag;
        struct DelegateBridge* __Hotfix0_GetTaskTagPauseCount;
        struct DelegateBridge* __Hotfix0_Dump;
    };

    struct ActorManager__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct ActorManager__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct ActorManager__VTable vtable;
    };

    struct Int32__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        int32_t vector[32];
    };

    struct Link {
        int32_t HashCode;
        int32_t Next;
    };

    struct Link__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct Link vector[32];
    };

    struct String__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct String* vector[32];
    };

    struct BaseActor__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct BaseActor* vector[32];
    };

    struct __declspec(align(8)) Dictionary_2_System_String_MoleMole_BaseActor___Fields {
        struct Int32__Array* table;
        struct Link__Array* linkSlots;
        struct String__Array* keySlots;
        struct BaseActor__Array* valueSlots;
        int32_t touchedSlots;
        int32_t emptySlot;
        int32_t count;
        int32_t threshold;
        void* hcp;
        void* serialization_info;
        int32_t generation;
    };

    struct Dictionary_2_System_String_MoleMole_BaseActor_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_String_MoleMole_BaseActor___Fields fields;
    };

    struct __declspec(align(8)) List_1_MoleMole_BaseActor___Fields {
        struct BaseActor__Array* _items;
        int32_t _size;
        int32_t _version;
    };

    struct List_1_MoleMole_BaseActor_ {
        void* klass;
        MonitorData* monitor;
        struct List_1_MoleMole_BaseActor___Fields fields;
    };

    struct __declspec(align(8)) Object_1__Fields {
        void* m_CachedPtr;
    };

    struct Object_1 {
        struct Object_1__Class* klass;
        MonitorData* monitor;
        struct Object_1__Fields fields;
    };

    struct Component_1__Fields {
        struct Object_1__Fields _;
    };

    struct Component_1 {
        struct Component_1__Class* klass;
        MonitorData* monitor;
        struct Component_1__Fields fields;
    };

    struct Transform__Fields {
        struct Component_1__Fields _;
    };

    struct Transform {
        void* klass;
        MonitorData* monitor;
        struct Transform__Fields fields;
    };

    struct Transform__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct Transform* vector[32];
    };

    struct __declspec(align(8)) Dictionary_2_System_String_UnityEngine_Transform___Fields {
        struct Int32__Array* buckets;
        struct Dictionary_2_TKey_TValue_Entry_System_String_UnityEngine_Transform___Array* entries;
        int32_t count;
        int32_t version;
        int32_t freeList;
        int32_t freeCount;
        struct IEqualityComparer_1_System_String_* comparer;
        void* keys;
        void* values;
        struct Object* _syncRoot;
    };

    struct Dictionary_2_System_String_UnityEngine_Transform_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_String_UnityEngine_Transform___Fields fields;
    };

    struct __declspec(align(8)) ActorManager__Fields {
        bool _initialized;
        struct Dictionary_2_System_String_MoleMole_BaseActor_* _actorDic;
        struct List_1_MoleMole_BaseActor_* _actorList;
        void* _questActorDic;
        void* _taskId2TaskDic;
        struct Dictionary_2_System_String_UnityEngine_Transform_* _transDic;
        void* _luaActorMgr;
        void* _curPausedTag;
        void* _action2TaskTags;
    };

    struct ActorManager {
        struct ActorManager__Class* klass;
        MonitorData* monitor;
        struct ActorManager__Fields fields;
    };

    struct BaseActor__Fields {
        struct LuaLogic__Fields _;
        void* OnActorEvent;
        struct String* _alias;
        struct String* _metaPath;
        struct ILuaActor* _luaActor;
        struct LuaAbilityParam* _luaAbilityParam;
        struct ActorManager* _actMgr;
        bool _isPaused;
        void* _taskQueues;
        void* _runningTaskList;
        bool _isDestroied;
        void* _actorHandlers;
        void* _coroutineDic;
        int32_t _coroutinueId;
        bool _isDayRegistered;
        void* _onLuaActorDayTime;
        bool _isNightRegistered;
        void* _onLuaActorNightTime;
        bool _isAbyssalPalaceDayRegistered;
        void* _onLuaActorAbyssalPalaceDayChanged;
        bool _isAbyssalPalaceNightRegistered;
        void* _onLuaActorAbyssalPalaceNightChanged;
        bool _isWeatherRegistered;
        void* _onSelfWeatherChanged;
        bool _isHourRegistered;
        void* _onLuaHour;
        void* _effectHandlerDic;
        uint32_t _lastSayDialogID;
        uint32_t _lastSayNarratorMainQuestID;
        void* _tag2Task;
        void* _tagTaskHasPaused;
        void* _tag2PauseCallback;
        void* _tag2ResumeCallback;
    };

    struct BaseActor__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        void* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
    };

    struct BaseActor {
        struct BaseActor__Class* klass;
        MonitorData* monitor;
        struct BaseActor__Fields fields;
    };

    enum class LuaHomeTask_GreetState__Enum : int32_t {
        None = 0x00000000,
        Entering = 0x00000001,
        Performing = 0x00000002,
        Leaving = 0x00000003,
    };

    enum class LuaTaskType__Enum : int32_t {
        NORMAL = 0x00000000,
        MOVE = 0x00000001,
        THREAT = 0x00000002,
        FREE_STYLE = 0x00000003,
        LIMIT_REGION = 0x00000004,
        BTN_TRANS = 0x00000005,
        STEER = 0x00000006,
        SPEECH_BUBBLE = 0x00000007,
        FORCE_WALK = 0x00000008,
        HOME = 0x00000009,
        SAFE_CIRCLE = 0x0000000a,
        NPC_FOLLOW_PLAYER = 0x0000000b,
    };


    struct __declspec(align(8)) LuaTask__Fields {
        void* StartEvent;
        void* FinishEvent;
        void* PauseEvent;
        void* ResumeEvent;
        void* TickEvent;
        void* DisappearEvent;
        void* AppearEvent;
        void* DestroyEvent;
        LuaTaskType__Enum _taskType;
        bool _isStarted;
        bool _isFinished;
        bool _isPaused;
        bool _isDestroyed;
        int32_t _taskQueueID;
        struct BaseActor* _actor;
        struct String* _tag;
        void* _syncCoDic;
    };

    struct __declspec(align(8)) DTimer__Fields {
        int32_t _JLJFEKLMDOF_k__BackingField;
        void* _callback;
        uint32_t KBPOAAOFJLM;
        float time1;
        float time2;
        bool isActiveMaybe;
    };

    struct DTimer {
        struct DTimer__Class* klass;
        MonitorData* monitor;
        struct DTimer__Fields fields;
    };

    enum class EntityType__Enum_1 : int32_t {
        None = 0x00000000,
        Avatar = 0x00000001,
        Monster = 0x00000002,
        Bullet = 0x00000003,
        AttackPhyisicalUnit = 0x00000004,
        AOE = 0x00000005,
        Camera = 0x00000006,
        EnviroArea = 0x00000007,
        Equip = 0x00000008,
        MonsterEquip = 0x00000009,
        Grass = 0x0000000a,
        Level = 0x0000000b,
        NPC = 0x0000000c,
        TransPointFirst = 0x0000000d,
        TransPointFirstGadget = 0x0000000e,
        TransPointSecond = 0x0000000f,
        TransPointSecondGadget = 0x00000010,
        DropItem = 0x00000011,
        Field = 0x00000012,
        Gadget = 0x00000013,
        Water = 0x00000014,
        GatherPoint = 0x00000015,
        GatherObject = 0x00000016,
        AirflowField = 0x00000017,
        SpeedupField = 0x00000018,
        Gear = 0x00000019,
        Chest = 0x0000001a,
        EnergyBall = 0x0000001b,
        ElemCrystal = 0x0000001c,
        Timeline = 0x0000001d,
        Worktop = 0x0000001e,
        Team = 0x0000001f,
        Platform = 0x00000020,
        AmberWind = 0x00000021,
        EnvAnimal = 0x00000022,
        SealGadget = 0x00000023,
        Tree = 0x00000024,
        Bush = 0x00000025,
        QuestGadget = 0x00000026,
        Lightning = 0x00000027,
        RewardPoint = 0x00000028,
        RewardStatue = 0x00000029,
        MPLevel = 0x0000002a,
        WindSeed = 0x0000002b,
        MpPlayRewardPoint = 0x0000002c,
        ViewPoint = 0x0000002d,
        RemoteAvatar = 0x0000002e,
        GeneralRewardPoint = 0x0000002f,
        PlayTeam = 0x00000030,
        OfferingGadget = 0x00000031,
        EyePoint = 0x00000032,
        MiracleRing = 0x00000033,
        Foundation = 0x00000034,
        WidgetGadget = 0x00000035,
        Vehicle = 0x00000036,
        DangerZone = 0x00000037,
        EchoShell = 0x00000038,
        HomeGatherObject = 0x00000039,
        Projector = 0x0000003a,
        Screen = 0x0000003b,
        CustomTile = 0x0000003c,
        FishPool = 0x0000003d,
        FishRod = 0x0000003e,
        CustomGadget = 0x0000003f,
        RoguelikeOperatorGadget = 0x00000040,
        ActivityInteractGadget = 0x00000041,
        SubEquip = 0x00000042,
        UIInteractGadget = 0x00000043,
        PlaceHolder = 0x00000063,
    };

    enum class TickState__Enum : int32_t {
        NormalTick = 0x00000000,
        Idle = 0x00000001,
        InterleavedTick = 0x00000002,
    };

    enum class CollisionDetectionMode__Enum : int32_t {
        Discrete = 0x00000000,
        Continuous = 0x00000001,
        ContinuousDynamic = 0x00000002,
    };

    struct GameObject__Fields {
        struct Object_1__Fields _;
    };

    struct GameObject {
        struct GameObject__Class* klass;
        MonitorData* monitor;
        struct GameObject__Fields fields;
    };

    struct GameObject__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct GameObject__StaticFields {
    };

    struct GameObject__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct GameObject__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct GameObject__VTable vtable;
    };

    struct SimpleSafeUInt32 {
        uint32_t _value;
    };

    struct SimpleSafeUInt16 {
        uint16_t _value;
    };

    struct Quaternion {
        float x;
        float y;
        float z;
        float w;
    };

    struct AsyncJob {
        void* _voucher;
        void* _job;
    };

    enum class VisionType__Enum : int32_t {
        VisionNone = 0x00000000,
        VisionMeet = 0x00000001,
        VisionReborn = 0x00000002,
        VisionReplace = 0x00000003,
        VisionWaypointReborn = 0x00000004,
        VisionMiss = 0x00000005,
        VisionDie = 0x00000006,
        VisionGatherEscape = 0x00000007,
        VisionRefresh = 0x00000008,
        VisionTransport = 0x00000009,
        VisionReplaceDie = 0x0000000a,
        VisionReplaceNoNotify = 0x0000000b,
        VisionBorn = 0x0000000c,
        VisionPickup = 0x0000000d,
        VisionRemove = 0x0000000e,
        VisionChangeCostume = 0x0000000f,
        VisionFishRefresh = 0x00000010,
        VisionFishBigShock = 0x00000011,
        VisionFishQteSucc = 0x00000012,
        EPFKMOIPADB = 0x00000013,
    };

    // Entity fields
    struct __declspec(align(8)) BaseEntity__Fields {
        struct Dictionary_2_System_UInt32_AIPerceptionInfo_* _aiPerceptionDic;
        struct ConfigEntity* jsonConfig;
        struct EntityExcelConfig* excelConfig;
        uint32_t _runtimeID_k__BackingField;
        uint32_t _preRuntimeID_k__BackingField;
        uint32_t _configID_k__BackingField;
        uint32_t _questID_k__BackingField;
        uint32_t _switchToQuestID_k__BackingField;
        struct SimpleSafeUInt32 campID;
        bool isDestroied;
        bool isToBeRemoved;
        bool isInCutscene;
        bool isDontDestroyGameObject;
        struct String* alias;
        int32_t order;
        bool isForceClientSynced;
        struct ComponentManager* _logicComponentManager;
        struct ComponentManager* _visualComponentManager;
        bool _isInited;
        struct Action_1_EvtEntityTimeScaleChange_* _onLevelTimeScaleChange;
        struct Action* _syncAnimatorSpeed;
        struct Action* _onTimeScaleChangedByAbility;
        struct EntityQueryIndex* _queryIndex;
        struct AbilityComponentProxy* _abilityProxy;
        struct TokenManager* _tokenMgr;
        VisionType__Enum _MCNHBKKJDCL_k__BackingField;
        bool _createDuringReconnectingSceneInitFinish_k__BackingField;
        bool _isCleared;
        bool _checkRemoveifCached_k__BackingField;
        bool _hasAddedInitialComponents;
        float BNPPLOPNGLD;
        bool _isEntityReady;
        struct Action_1_BaseEntity_* onComponentInitPostCallback;
        struct Action_1_BaseEntity_* onEntityReadyPreCallback;
        struct Action_1_BaseEntity_* onEntityReadyBeforePostCallback;
        bool _IsTickable;
        bool _forceTickVisualComMgrIfDisable_k__BackingField;
        bool _logicHasAnyTickComponent_k__BackingField;
        bool _visualHasAnyTickComponent_k__BackingField;
        bool _logicHasAnyLateTickComponent_k__BackingField;
        bool _visualHasAnyLateTickComponent_k__BackingField;
        bool isLightInitializationEntity;
        bool _canBeDestroied_k__BackingField;
        bool _isDestroying;
        struct Action_1_BaseEntity_* onEntityRemovedCallback;
        struct Action_1_BaseEntity_* onDestroyCallback;
        bool _isAlive;
        struct Action_1_BaseEntity_* onSetAliveFalseCallback;
        bool _isActive;
        struct Action_1_BaseEntity_* preAnimatorInitUpdateCallback;
        bool _needSetActiveOnEntityReady;
        bool _setActiveOnEntityReady;
        struct Action_2_BaseEntity_Boolean_* onSetActiveCallback;
        bool _withGameObjWhenSetActive;
        bool _isLightActive;
        bool _playDefault;
        bool _deepIfInactive;
        bool _forceSkipAnimatorUpdate;
        bool _hasActiveInited;
        bool _duringSetComponentsEnabledOnSetActive_k__BackingField;
        float _lastTimeScale;
        float _timeScale;
        bool ignoreLevelTimeScale;
        struct FixedStack_1_System_Single_* _timeScaleStack;
        struct LCAbilityState* _lcAblityState;
        uint32_t _nextComponentID;
        EntityType__Enum_1 entityType;
        bool _isAuthority;
        uint32_t authorityPeerId;
        bool FEFIECBENHD;
        bool MGNKEDPIJKG;
        struct HashList_1_BaseComponent_* _componentsForEntityTickManager;
        float _lastTickTime_k__BackingField;
        struct List_1_BaseEntity_BaseEntity_ComponentInitNotifyData_* _notifyListOnComponentInit;
        struct Dictionary_2_System_String_DynamicCollisionInfo_* _collisionTagDic;
        bool _needSafeEntityInit;
        struct List_1_EntitySafeCmd_* _entitySafeCmds;
        struct Vector3 _sharedPosition;
        struct Vector3 _sharedForward;
        struct MEventDispatcher* _eventDispatcher;
        struct Func_1_Boolean_* onShouldNoPause;
        struct Action_3_UnityEngine_TickState_Boolean_Boolean_* onAnimatorTickStateChange;
        struct HashList_1_IRenderable_* _extraRenderers;
        struct HashSet_1_IRequestOwnerEntityNoPauseTask_* _noPauseTaskRequests;
        bool PNBKIOPIIKA;
        bool IMKKHNIODFJ;
        TickState__Enum _currentAnimatorTickState;
        struct EntityTickBalanceProxy* _tickBalanceProxy;
        bool isKinematicRigidbody;
        bool _PNECEMJLAHN_k__BackingField;
        bool _IFOBCICMOJM_k__BackingField;
        float __fullTickSqrMag_k__BackingField;
        int32_t _greaterToDisableInterval_k__BackingField;
        struct Func_1_Single_* _getBalanceTickDeltaTimeHandler;
        struct Func_1_Boolean_* _getRequestPauseHandler;
        uint64_t animatorConfigPath;
        struct Config_ConfigAnimator* _animatorConfig;
        struct AnimatorOverrideController* _animatorOverrideController;
        int32_t _lastSetOverrideAnimeFrame;
        struct AnimatorOverrideController* _originAnimatorController;
        struct Dictionary_2_System_String_BaseEntity_BaseEntity_AnimeLoadInfo_* _curLoadedAnime;
        struct RecycledLinkedList_1_BaseEntity_BaseEntity_AnimeLoadInfo_* _needFlushResetAnimes;
        int32_t _curForceCacheFreeStyleId;
        struct EntityTimerReceiver* _animeRecycleTimer;
        struct Coroutine* _checkAnimeLoadFinishCoroutine;
        struct BaseEntity_BaseEntity_AnimeOverrideFlushList* _animatorOverrideFlushList;
        struct EntityPreloader* _onCreatePreloader;
        struct EntityPreloader* _onCombatPreloader;
        struct EntityPreloader* _onSceneDataNotifyPreloader;
        uint32_t _gameObjectResourceHandle;
        int32_t _preloadIndex;
        struct GameObject* _preLoadObject;
        struct Action_1_BaseEntity_* _jsonConfigLoadedCallback;
        struct MonoVisualEntityTool* _visualEntityTool_k__BackingField;
        struct GameObject* _rootGameObject_k__BackingField;
        struct GameObject* _offsetDummyObject;
        struct GameObject* _animatorObject;
        bool _isForceDisableGameObjectPool;
        struct MaterialGroup* _defaultGroup;
        struct MaterialGroup* _instancedMaterialGroup;
        struct GameObject* _gameObject_k__BackingField;
        bool _enableSyncFromTransform_k__BackingField;
        struct Transform* _transform_k__BackingField;
        struct Transform* _gameObjectParent_k__BackingField;
        bool forceUpdateRigidbodyRotationCurFrame;
        struct Rigidbody* _mRigidbody;
        CollisionDetectionMode__Enum _defaultCollisionDetectionMode;
        CollisionDetectionMode__Enum _curCollisionDetectionMode;
        struct Animator* _animator;
        bool _animatorCullModeExternal;
        struct Action_1_BaseEntity_* finishLoadCallback;
        float cachedEntityDist;
        float localEntityDist;
        bool localEntityWithGO;
        bool _isLoaded_k__BackingField;
        struct Vector3 _initPos_k__BackingField;
        struct Quaternion _initRotation_k__BackingField;
        float _initUniformScale_k__BackingField;
        uint64_t _prefabPathHash_k__BackingField;
        bool _forceDontUseUpdateRigidbody;
        bool _useDummyPrefab;
        bool _createDummyGameObject;
        struct AsyncJob _loadJob;
        struct WorldTimer* _infoTimer;
        struct EntityGameObjectNode* _gameObjectNode;
        bool _isGameObjectFromPool;
        bool _isEntityAsyncLoad;
        bool _hasGameObject_k__BackingField;
        float _curMass;
        struct FixedFloatStack* _massRatio;
        bool _enableSetPostiion;
        struct Vector3 _lastPosInParent;
        struct Collider__Array* LIFJOPNILOC;
        int32_t LPNNDJDEGMI;
        int32_t GFMAMAGCBNE;
        int32_t IPKBDFGENOE;
        bool _isForceDisableEffect;
        bool _isActorHided;
        bool _isRoomHided;
        struct Vector3 LMBBHMDGPGE;
        struct Quaternion BFHGMCMIANA;
        float LMACHNHENOB;
        bool FJBBJDDFOIA;
        struct Vector3 PDCOCJPHGAK;
        struct RuntimeAnimatorController* _authorityRuntimeAnimatorController;
        struct RuntimeAnimatorController* _remoteRuntimeAnimatorController;
        uint32_t _authorityRuntimeAnimatorHandler;
        uint32_t _remoteRuntimeAnimatorHandler;
        struct Dictionary_2_System_Int32_System_Boolean_* _boolPersistentParams;
        struct Dictionary_2_System_Int32_System_Int32_* _intPersistentParams;
        struct Dictionary_2_System_Int32_System_Single_* _floatPersistentParams;
        struct List_1_System_ValueTuple_5_* _linearSmoothAnimatorFloats;
    };

    struct BaseEntity {
        void* klass;
        MonitorData* monitor;
        struct BaseEntity__Fields fields;
    };

    struct EntityActor__Fields {
        struct BaseActor__Fields _;
        void* _lcActor;
        struct BaseEntity* _entity;
        bool _isDaily;
        void* SensibleInfoEvent;
        void* _curDitherCallBack;
        bool _ensureDitherCallBack;
        void* _disappearFinishCallback;
        bool _isActorOnly;
        bool _isDisappearToDestroy;
        struct DTimer* _disappearTimer;
    };

    struct EntityActor {
        struct EntityActor__Class* klass;
        MonitorData* monitor;
        struct EntityActor__Fields fields;
    };

    struct __declspec(align(8)) SpeechBubbleData__Fields {
        uint32_t _dirtyFlag_k__BackingField;
        bool _lastCondRet_k__BackingField;
        void* conditions;
        int32_t weight;
        uint32_t initDialog;
    };

    struct SpeechBubbleData {
        struct SpeechBubbleData__Class* klass;
        MonitorData* monitor;
        struct SpeechBubbleData__Fields fields;
    };

    struct LuaHomeTask__Fields {
        struct LuaTask__Fields _;
        struct EntityActor* _entityActor;
        void* _actionList;
        void* _speechBubbleGroup;
        int32_t _curActionIndex;
        uint32_t _condDirtyFlag;
        bool _needCheckAction;
        bool _needCheckActionForce;
        bool _needRefreshAction;
        void* _curFreeStyleData;
        float _curFreeStyleLeftTime;
        struct Vector3 _curActionPointPos;
        struct Vector3 _curActionPointForward;
        float _curWaitingQuitFreeStyle;
        void* _greetConfig;
        bool _allowGreet;
        float _curGreetTurnTime;
        struct Vector3 _curGreetForward;
        LuaHomeTask_GreetState__Enum _curGreetState;
        float _lastGreetLeaveTime;
        struct SpeechBubbleData* _curSpeechBubbleData;
        uint32_t _curSpeechBubbleDialogId;
        float _nextSpeechBubbleTime;
        float _curSpeechBubbleLeftTime;
        uint32_t _nextSpeechBubbleDialogId;
        bool _isSpeechBubblePlayVoice;
        bool _isInitFinish;
        bool _isSelfPause;
        bool _isSelfDisappear;
        bool _registAnimeReady;
        void* _tempCondContainerList;
    };

    struct LuaHomeTask {
        void* klass;
        MonitorData* monitor;
        struct LuaHomeTask__Fields fields;
    };

    struct __declspec(align(8)) MonoLevelMap_AreaFogConfig__Fields {
        uint32_t AreaID;
        float blend;
        struct String__Array* blockName;
        struct String__Array* channnel;
    };

    struct MonoLevelMap_AreaFogConfig {
        struct MonoLevelMap_AreaFogConfig__Class* klass;
        MonitorData* monitor;
        struct MonoLevelMap_AreaFogConfig__Fields fields;
    };

    struct MonoLevelMap_AreaFogConfig__Array {
        struct MonoLevelMap_AreaFogConfig__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct MonoLevelMap_AreaFogConfig* vector[32];
    };


    struct Behaviour__Fields {
        struct Component_1__Fields _;
    };


    struct MonoBehaviour__Fields {
        struct Behaviour__Fields _;
    };

    struct MonoSpriteProxy__Fields {
        struct MonoBehaviour__Fields _;
        void* FHGFLEBJCGO;
    };

    struct Animator__Fields {
        struct Behaviour__Fields _;
    };

    struct Animator {
        void* klass;
        MonitorData* monitor;
        struct Animator__Fields fields;
    };

    struct Color {
        float r;
        float g;
        float b;
        float a;
    };

    struct UIBehaviour__Fields {
        struct MonoBehaviour__Fields _;
    };

    struct Graphic__Fields {
        struct UIBehaviour__Fields _;
        void* m_Material;
        bool m_UseRendererColor;
        struct Color m_Color;
        bool m_RaycastTarget;
        void* m_RectTransform;
        void* m_CanvasRenderer;
        void* m_Canvas;
        bool m_VertsDirty;
        bool m_MaterialDirty;
        void* m_OnDirtyLayoutCallback;
        void* m_OnDirtyVertsCallback;
        void* m_OnDirtyMaterialCallback;
        void* m_ColorTweenRunner;
        bool _useLegacyMeshGeneration_k__BackingField;
        bool _verticesDirtyWhenLightweightDeactive_k__BackingField;
        bool _materialDirtyWhenLightweightDeactive_k__BackingField;
    };

    struct MaskableGraphic__Fields {
        struct Graphic__Fields _;
        bool m_ShouldRecalculateStencil;
        void* m_MaskMaterial;
        bool m_ShouldRecalculateSmoothMask;
        void* m_SmoothMaskMaterial;
        void* m_SmoothMask;
        void* m_ParentMask;
        bool m_Maskable;
        bool m_IncludeForMasking;
        void* m_OnCullStateChanged;
        bool m_ShouldRecalculate;
        int32_t m_StencilValue;
        void* m_Corners;
    };

   /*struct MaskableGraphic {
        struct MaskableGraphic__Class* klass;
        MonitorData* monitor;
        struct MaskableGraphic__Fields fields;
    };*/

    struct Text__Fields {
        struct MaskableGraphic__Fields _;
        void* m_FontData;
        struct String* m_Text;
        void* m_TextCache;
        void* m_TextCacheForLayout;
        bool m_DisableFontTextureRebuiltCallback;
        struct Color m_CachedColor;
        void* m_TempVerts;
    };

    struct Text {
        struct Text__Class* klass;
        MonitorData* monitor;
        struct Text__Fields fields;
    };
    struct Text__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct Text* vector[32];
    };

    struct Vector2 {
        float x;
        float y;
    };

    struct MonoLevelMap__Fields {
        struct MonoSpriteProxy__Fields _;
        struct MonoLevelMap_AreaFogConfig__Array* areaConfig;
        float fogAnimSpeed;
        float fogAreaAnimSpeed;
        int32_t _cellRectSize;
        int32_t _cellSize;
        struct Transform* _mapArea;
        struct Transform* MapRoomAnchor;
        struct Transform* _fogArea;
        struct Transform* _guidArea;
        struct Animator* placeNames;
        struct Animator* areaNames;
        struct Text__Array* placeTextList;
        struct Text__Array* areaTextList;
        void* exploreDegreeList;
        void* HAIFLCJCDPN;
        void* FFBIMCFJIIP;
        struct Vector2 vec2;
        struct Color OKKOJCIOMAF;
        struct Color IDICJLOMLML;
        bool KDGCCIAMPEP;
        float OPJFODGABDE;
        void* HKAINLLOIOO;
        float LDKBKFCJFGG;
        float LCDJLIPCPPH;
        struct String* _terrainMatPrefix;
        void* sceneTag;
        void* sceneTagRelatedTerrain;
        bool isInterior;
        bool hasMultiFloor;
        bool isBigWorld;
        bool needExploreDegree;
        struct String* _terrainMatName;
        struct String* roomIconName;
        int32_t PPKNEBBAOJK;
        struct String* currSceneTag;
        void* LDBLNDEJGNB;
        int32_t _playerCurrentFloor;
        void* PNHFGGFPDDP;
        struct GameObject* JADKKHKDDHD;
        uint32_t AOGIJPKLAFB;
        struct GameObject* OAPJGOIJCBK;
        struct AsyncJob JMFIHNONJOH;
        struct GameObject* markPointArea;
        void* dicQuestArea;
        void* markAreaAnchor;
        void* markAreaAnchorMiniMap;
        struct GameObject* exploreDegreePrefab;
        uint32_t PNGBAMGLJPP;
        struct GameObject* EKMBOPLOOFA;
        void* NKNPJOCFKJG;
    };

    struct MonoLevelMap {
        void* klass;
        MonitorData* monitor;
        struct MonoLevelMap__Fields fields;
    };

    enum class MoleMole_Config_MarkType__Enum : int32_t {
        Default = 0x00000000,
        TransPoint = 0x00000001,
        Quest = 0x00000002,
        Custom = 0x00000003,
        LocalAvatar = 0x00000004,
        Companion = 0x00000005,
        Monster = 0x00000006,
        NearHint = 0x00000008,
        ScenePoint = 0x00000009,
        Task = 0x0000000a,
        Boss = 0x0000000b,
        Talk = 0x0000000c,
        PacketAnchor = 0x0000000d,
        Widget = 0x0000000e,
        FlightChallenge = 0x0000000f,
        Hunting = 0x00000010,
        Routine = 0x00000011,
        ActivitySearchRegion = 0x00000012,
        GalleryChallenge = 0x00000013,
        HomeworldDynamic = 0x00000014,
        SignalPoint = 0x00000015,
        Vehicle = 0x00000016,
        HomeworldFurnitureSuite = 0x00000017,
        Activity = 0x00000018,
        HomeworldFarmField = 0x00000019,
        Offering = 0x0000001a,
        QuestAcception = 0x0000001b,
    };

    enum class MoleMole_Config_MarkIconType__Enum : int32_t {
        Default = 0x00000000,
        MarkChurch = 0x00000001,
        MarkKnights = 0x00000002,
        MarkPub = 0x00000003,
        MarkSouvenir = 0x00000004,
        MarkRestaurant = 0x00000005,
        MarkGeneralCargo = 0x00000006,
        MarkBlacksmith = 0x00000007,
        MarkTeamArranger = 0x00000008,
        MarkDailyTask = 0x00000009,
        MarkRandomTask = 0x0000000a,
        MarkAdventurers = 0x0000000b,
        MarkAlchemy = 0x0000000c,
        MarkSeaLampGiving = 0x0000000d,
        MarkInvestigationMonster = 0x0000000e,
        MarkBlacksmith_liyue = 0x0000000f,
        MarkSouvenir_liyue = 0x00000010,
        MarkRestaurant_liyue = 0x00000011,
        MarkReputation = 0x00000012,
        MarkReputation_liyue = 0x00000013,
        MarkReputation_Inazuma = 0x00000014,
        MarkBlacksmith_Inazuma = 0x00000015,
        MarkSouvenir_Inazuma = 0x00000016,
        MarkRestaurant_Inazuma = 0x00000017,
        MarkGroupLink = 0x00000018,
        MarkFish = 0x00000019,
        MarkFish_liyue = 0x0000001a,
        MarkFish_Inazuma = 0x0000001b,
        MarkGroupLink_Area = 0x0000001c,
        MarkTransPoint = 0x00000064,
        MarkTransPointLocked = 0x00000065,
        MarkPortal = 0x00000066,
        MarkDungeonEntry = 0x00000067,
        MarkDungeonEntryLocked = 0x00000068,
        MarkWeeklyDungeonEntry = 0x00000069,
        MarkWeeklyDungeonEntryLocked = 0x0000006a,
        MarkDailyDungeonEntry = 0x0000006b,
        MarkDailyDungeonEntryLocked = 0x0000006c,
        MarkTowerDungeonEntry = 0x0000006d,
        MarkTowerDungeonEntryLocked = 0x0000006e,
        MarkDailyDungeonEntryToBeExplored = 0x0000006f,
        MarkTowerDungeonEntryToBeExplored = 0x00000070,
        MarkEffigyDungeonEntry = 0x00000071,
        MarkEffigyDungeonEntryLocked = 0x00000072,
        MarkFleurFairDungeonEntry = 0x00000073,
        MarkBlitzRushDungeonEntry = 0x00000074,
        MarkHachiDungeonEntry = 0x00000075,
        MarkMiniEldritchDungeonEntry = 0x00000076,
        MarkGoddessLocked = 0x000000c7,
        MarkGoddessUnlocked = 0x000000cc,
        MarkPacketAnchor = 0x000000cd,
        MarkQuest = 0x0000012c,
        MarkDangerousQuest = 0x0000012d,
        MarkQuestArea = 0x0000012e,
        MarkDangerousQuestArea = 0x0000012f,
        MarkCustom = 0x00000190,
        MarkCustomBoss = 0x00000192,
        MarkCustomBox = 0x00000193,
        MarkCustomCollect = 0x00000194,
        MarkCustomCooking = 0x00000195,
        MarkCustomMainTask = 0x00000197,
        MarkCustomMonster = 0x00000198,
        MarkCustomSlime = 0x0000019b,
        MarkCustomTrap = 0x0000019c,
        MarkCustomWind = 0x0000019d,
        MarkCustomFish = 0x0000019e,
        MarkLocalAvatar = 0x000001f4,
        MarkPlayer1 = 0x000001f5,
        MarkPlayer2 = 0x000001f6,
        MarkPlayer3 = 0x000001f7,
        MarkPlayer4 = 0x000001f8,
        MarkBoredMonster = 0x000001f9,
        MarkRadarHint = 0x000001fa,
        MarkActivity = 0x000001fb,
        MarkTalk = 0x000001fc,
        MarkMiscsMarvs = 0x000001fd,
        MarkActivityAsterLittle = 0x000001fe,
        MarkActivityAsterMiddle = 0x000001ff,
        MarkRadarHintArea = 0x00000200,
        MarkActivityAsterlarge = 0x00000201,
        MarkHuntingArea = 0x00000202,
        MarkActivityAsterMiddleNPC = 0x00000203,
        MarkWidgetSeverDetectorArea = 0x00000204,
        MarkActivityFlightChallengePoint = 0x00000205,
        MarkElderTree = 0x00000206,
        MarkElderTreeEvent = 0x00000207,
        MarkWidgetTreasureMapArea = 0x00000208,
        MarkActivityTreasureMapNPC = 0x00000209,
        MarkActivityDragonSpineBoss = 0x0000020a,
        MarkActivityBlessing = 0x0000020b,
        MarkActivityMonsterBannerDrakePrimoRock = 0x0000020c,
        MarkActivityExpeditionChallengeArea = 0x0000020d,
        MarkMechanicisNPC = 0x0000020e,
        MarkActivityWaterSpriteExploreArea = 0x0000020f,
        MarkActivityArenaChallenge = 0x00000210,
        MarkActivityFleurFairFall = 0x00000211,
        MarkActivityFleurFairBalloon = 0x00000212,
        MarkActivityWaterSpriteBoss = 0x00000213,
        MarkActivitySummerTimeRace = 0x00000214,
        MarkActivityRegionSearch = 0x00000258,
        MarkGalleryChallenge = 0x00000259,
        MarkActivityFleurFairNPC = 0x0000025a,
        MarkChannellerSlabCampLow = 0x0000025b,
        MarkChannellerSlabCampMiddle = 0x0000025c,
        MarkChannellerSlabCampHigh = 0x0000025d,
        MarkChannellerSlabOneOffDungeon = 0x0000025e,
        MarkChannellerSlabLoopDungeon = 0x0000025f,
        MarkChannellerSlabNPC = 0x00000260,
        MarkActivityMiniTomoHiliWeiArea = 0x00000261,
        MarkActivityHideAndSeekNPC = 0x00000262,
        MarkHomeworldDjinn = 0x00000263,
        MarkHomeworldDjinnWeekend = 0x00000264,
        MarkHomeworldMainHouse = 0x00000265,
        MarkHideAndSeekHunter = 0x00000266,
        MarkActivityBuoyantCombatPoint = 0x00000267,
        MarkActivityBounceConjuring = 0x00000268,
        MarkHomeworldNpc = 0x00000269,
        MarkSummerIsleSignalPoint = 0x0000026c,
        MarkVehicleSummonPoint = 0x0000026d,
        MarkVehicleSummonPointLocked = 0x0000026e,
        MarkBounceConjuringNPC = 0x00000271,
        MarkVehicleSkiff = 0x00000272,
        MarkHomeworldFurnitureSuite = 0x00000276,
        MarkHomeworldTransPoint = 0x00000277,
        MarkHomeworldFarmField1 = 0x00000279,
        MarkHomeworldFarmField2 = 0x0000027a,
        MarkHomeworldFarmField3 = 0x0000027b,
        MarkActivityTreasureMapChallenge = 0x000002bc,
        MarkActivityBlitzRushParkour = 0x000002bd,
        MarkActivityPerpetualNPC = 0x000002c1,
        MarkOraionokamiTree = 0x000002c6,
        MarkSumoDungeon = 0x000002c7,
        MarkMoonfinTrialChallenge = 0x000002c8,
        MarkMoonfinTrialFinal = 0x000002c9,
        MarkLunaRiteExploreArea = 0x000002d0,
        MarkLunaRiteNPC = 0x000002d1,
        MarkLunaRiteCrystal = 0x000002d2,
        MarkLunaRiteChest = 0x000002d3,
        MarkRoguelike = 0x000002da,
        MarkBugyowu = 0x00000320,
        MarkChashitsu = 0x00000321,
        MarkHomeworldPaimon = 0x00000322,
        MarkMusicGameNPC = 0x00000323,
        MarkGrowFlowersNPC = 0x00000324,
        MarkHachiStealthChallenge = 0x00000325,
        MarkHachiBattleChallenge = 0x00000326,
        MarkWinterCampSnowman = 0x0000032a,
        MarkActivityWinterCampBoss = 0x0000032b,
        MarkAnimalCaptureShop = 0x00000334,
        MarkAlcorTransmit = 0x00000335,
        MarkQunyugeTransmit = 0x00000336,
        MarkAshanpoNPC = 0x0000033e,
        MarkPotionDungeonEntry = 0x00000348,
        MarkProjectionGameEntry = 0x00000352,
        MarkLanternRiteShipSummonPoint = 0x0000035c,
        MarkLanternRiteShipSummonPointLocked = 0x0000035d,
        MarkMichiaeOffering = 0x00000366,
        MarkBartenderNPC = 0x00000367,
        MarkMichiaeChest = 0x00000368,
        MarkMichiaeChallenge = 0x00000369,
        MarkCustomLevel = 0x0000036a,
        MarkLuminanceStoneNPC = 0x00000a29,
        MarkCrystalLink = 0x00000a2a,
        MarkQuestAcception = 0x00000a2b,
        MarkIrodoriFlowerNPC = 0x00000a32,
        MarkIrodoriPhotoNPC = 0x00000a33,
        MarkIrodoriMasterNPC = 0x00000a34,
        MarkIrodoriChessNPC = 0x00000a35,
        MarkMusicGameV3NPC = 0x00000a8d,
        MarkActivityGachaNPC = 0x00000a8e,
        MarkRogueDiary = 0x00000a8f,
        MarkCocoonSpace = 0x00000a90,
    };
    enum class MoleMole_Config_MarkOrder__Enum : int32_t {
        None = 0x00000000,
        LocalPlayer = 0x00000001,
        OtherPlayer = 0x00000002,
        QuestMain = 0x00000003,
        QuestBranch = 0x00000004,
        Radar = 0x00000005,
        TransportGoddess = 0x00000006,
        Dungeon = 0x00000007,
        QuestEvent = 0x00000008,
        QuestActivity = 0x00000009,
        QuestWorld = 0x0000000a,
        QuestRandom = 0x0000000b,
        Ore = 0x0000000c,
        Activity = 0x0000000d,
        Custom = 0x0000000e,
        Monster = 0x0000000f,
        TransportOther = 0x00000010,
        NpcAdventure = 0x00000011,
        NpcActivity = 0x00000012,
        Area = 0x00000013,
        Default = 0x00000014,
        NpcOther = 0x00000015,
        Vehicle = 0x00000016,
        QuestAcception = 0x00000017,
        HomeworldMainHouse = 0x000003e9,
        HomeworldFarmField = 0x000003ea,
        HomeworldFurnitureSuite = 0x000003eb,
        HomeworldDjinn = 0x000003ec,
        HomeworldNpc = 0x000003ed,
        HomeworldTransPoint = 0x000003ee,
    };

    enum class MoleMole_Config_MarkVisibilityType__Enum : int32_t {
        None = 0x00000000,
        Invisible = 0x00000001,
        Around = 0x00000002,
        Always = 0x00000003,
    };

    enum class IACLLAMDHGF__Enum : int32_t {
        None = 0x00000000,
        Boss = 0x00000001,
        Character = 0x00000002,
        Paimon = 0x00000003,
    };

    enum class LBOKOEJFMEP__Enum : int32_t {
        Default = 0x00000000,
        Teleport = 0x00000001,
        Trace = 0x00000002,
    };

    struct MonoUIProxy__Fields {
        struct MonoSpriteProxy__Fields _;
        void* _animator;
        float _fadeInDuration;
        float _fadeOutDuration;
        void* _coroutine;
        void* _proxySet;
        void* _delegatedInstanceSet;
    };

    struct MonoMapCursor__Fields {
        struct MonoBehaviour__Fields _;
        bool CCGMBOCLHDI;
        struct MonoMapMark* mapMark;
        void* LODFBKEGONO;
        struct Vector3 someVec1;
        struct Vector3 someVec2;
    };

    struct MonoMapCursor {
        struct MonoMapCursor__Class* klass;
        MonitorData* monitor;
        struct MonoMapCursor__Fields fields;
    };

    struct MonoInLevelMapPage__Fields {
        struct MonoUIProxy__Fields _;
        struct Transform* _GrpMapTrans;
        struct MonoPrefabPlugin* _prefabPlugin;
        struct MonoElementSwitch* _elementSwitch;
        struct MonoMapMarkTips* _markTips;
        struct Button_1* _markTipsFreeBtn;
        struct RectTransform* _markContainer;
        struct RectTransform__Array* _markContainerLayers;
        struct GameObject* _markPrefab;
        struct MonoLevelMapMarkContainer* _container;
        struct RectTransform* _goddessLevelGrp;
        struct RectTransform* _rewardTipsGrp;
        struct MonoSimpleReusableList* _rewardTipsList;
        struct RectTransform* _cursor;
        struct RectTransform* _ps4ButtonsGrp;
        struct RectTransform* _joypadMapButtonsGrp;
        bool _joypadMoveMapInverted;
        float _joypadMoveMapSensitivity;
        bool _joypadMoveCursorInverted;
        float _joypadMoveCursorSensitivity;
        float _joypadAttrackSpeed;
        struct MonoSliderWithButton* slider;
        struct GameObject* playerIndicator;
        struct RectTransform* playerIndicatorParent;
        struct MonoMapCursor* _monoMapCursor;
        struct InputField* _customMarkTipsInputField;
        struct MonoMaterialItemRow* _resin;
        struct RectTransform* _cycleDungeonLookupGrp;
        struct MonoUIContainer* _cycleDungeonLookupToggle;
        struct Text* _cycleDungeonLookupText;
        struct List_1_Queue_1_MoleMole_MonoMapMark_* KEIOHDAFIOC;
        struct GameObject* _exploreDegreeGrp;
        struct Text* _exploreArea;
        struct Text* _exploreDegree;
        struct Button_1* exploreTagButton;
        struct GameObject* redPointAnchorExploreDegree;
        struct Image_1* exploreDegreeImage;
        struct GameObject* mapTagSwitch;
        struct MonoGridScroller* mapTagScroller;
        struct MonoElementSwitch* mapTagElementSwitch;
        struct List_1_UnityEngine_GameObject_* topInfoTagGroup;
        struct GameObject* dungeonTowerGO;
        struct Text* dungeonTowerText;
        struct MonoUIContainer* dungeonBtn;
        struct Sprite* _questTrackSprite;
        struct Sprite* _commonTrackSprite;
        struct Button_1* homeworldVisitorBtn;
        struct Text* _homeworldVisitorLabel;
        struct MonoUIContainer* _homeworldVisitorPS4Container;
        struct Animator* NFGDFFBFOCF;
    };

    struct MonoInLevelMapPage {
        struct MonoInLevelMapPage__Class* klass;
        MonitorData* monitor;
        struct MonoInLevelMapPage__Fields fields;
    };

    struct ConfigMarkIcon {
        struct String* IFMMCPNGPDI;
        struct SimpleSafeUInt32 GNBMICNFLBF;
        MoleMole_Config_MarkType__Enum markType;
        struct String* HDPJJBGHFCH;
        bool BLBOCGLEGAG;
        struct String* PPCPDJAHHNK;
        struct String* ENFNJCEIBIB;

        MoleMole_Config_MarkOrder__Enum IFEKPECENLC;

        MoleMole_Config_MarkOrder__Enum RadarVisibility;
        MoleMole_Config_MarkOrder__Enum mapVisibility;
        bool JABFACDGLDF;
        bool KKHGMKOLGDK;
        IACLLAMDHGF__Enum typeActor;
        LBOKOEJFMEP__Enum typeMovement;
    };

    struct ColorStyle_MarkPointAreaColor {
        struct Color mainColor;
        struct Color edgeColor;
    };

    struct Nullable_1_UInt32_ {
        uint32_t value;
        bool has_value;
    };

    struct Nullable_1_Double_ {
        double value;
        bool has_value;
    };

    struct MonoMapMark__Fields {
        struct MonoSpriteProxy__Fields _;
        MoleMole_Config_MarkType__Enum _markType;
        MoleMole_Config_MarkIconType__Enum _iconType;
        MoleMole_Config_MarkOrder__Enum _markOrder;
        uint32_t _identifier;
        MoleMole_Config_MarkVisibilityType__Enum realRadarVisibility;
        MoleMole_Config_MarkVisibilityType__Enum realMapVisibility;
        struct String* markerName;
        bool _alwaysShow;
        bool showHeight;
        float height;
        bool isHide;
        bool hideIcon;
        bool hideUnderMist;
        struct Transform* _contentRoot;
        struct Button_1* _actionButton;
        struct RectTransform* _pointGrp;
        struct Image_1* _icon;
        struct MonoUIEffect* _unlockEffect;
        struct MonoUIEffect* _effect;
        struct GameObject* _defaultEffectObj;
        struct GameObject* _customEffectObj;
        struct MonoPrefabPlugin* _effectPrefabs;
        struct MonoAsyncPrefabPlugin* _asyncPrefabs;
        struct GameObject* _areaGrp;
        struct Material__Array* _materials;
        struct RectTransform* _rectTrans;
        struct Vector2 _levelMapPos;
        struct ConfigMarkIcon config;
        uint32_t _dungeonIconLabelHandle;
        struct GameObject* _dungeonIconLabel;
        uint32_t _dungeonIconTipsHandle;
        struct GameObject* _dungeonIconTips;
        struct GeneralMarkData* generalMapData;
        bool NLCJDMBMKPC;
        int32_t floor;
        bool _up;
        struct String* _currEffectName;
        struct ParticleSystem* _currEffect;
        float markAreaRadius;
        struct ColorStyle_MarkPointAreaColor _markPointAreaColor;
        struct RectTransform* layerParent;
        bool _inLayer;
        int32_t _layer;
        struct Nullable_1_UInt32_ _appearAudio;
        uint32_t _configEffectHandle;
        struct GameObject* _configEffectIns;
        struct GameObject* _completeIcon;
        struct Transform* _dungeonIconLabelRoot;
        struct GameObject* _bossGrp;
        struct Image_1* _bossIcon;
        struct Image_1* _bossIconNoBG;
        struct Transform* _bossIconRoot;
        struct Transform* _bossIconRootNoBG;
        struct Transform* _bossEffect;
        struct String* imgPath;
        struct GameObject* _characterGrp;
        struct Image_1* _characterIcon;
        struct Transform* _characterIconRoot;
        struct Transform* _characterIconRewardTrans;
        struct Transform* _characterIconTalkTrans;
    };

    struct MonoMapMark {
        void* klass;
        MonitorData* monitor;
        struct MonoMapMark__Fields fields;
    };

    struct LBBCJFOEBGD {
        uint32_t PDELCHOIIIE;
        uint32_t EHOMJENLOLF;
        bool JHNLKEHCJDM;
        uint32_t NKFGELEMFHG;
        bool MCBNNKODMDP;
    };

    struct __declspec(align(8)) GeneralMarkData__Fields {
        uint32_t sceneID;
        MoleMole_Config_MarkType__Enum markType;
        uint32_t markID;
        struct Vector3 position;
        MoleMole_Config_MarkIconType__Enum iconType;
        void* entity;
        bool hideOnMove;
        bool hideIcon;
        bool hideUnderMist;
        void* mapMarkPoint;
        struct Vector3 positionOffset;
        struct LBBCJFOEBGD sceneId;
        bool hideOnMapAndRadar;
        float radius;
        bool tracking;
        bool deleteStopTrack;
        bool hideTrace;
        struct Nullable_1_UInt32_ worldAreaID;
        bool showWhenAreaLocked;
    };

    struct GeneralMarkData {
        struct GeneralMarkData__Class* klass;
        MonitorData* monitor;
        struct GeneralMarkData__Fields fields;
    };

    enum class EnterType__Enum : int32_t {
        EnterNone = 0x00000000,
        EnterSelf = 0x00000001,
        EnterGoto = 0x00000002,
        EnterJump = 0x00000003,
        EnterOther = 0x00000004,
        EnterBack = 0x00000005,
        EnterDungeon = 0x00000006,
        EnterDungeonReplay = 0x00000007,
        EnterGotoByPortal = 0x00000008,
        EnterSelfHome = 0x00000009,
        EnterOtherHome = 0x0000000a,
        FCBBIIAOAGG = 0x0000000b,
    };

    struct UInt32__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint32_t vector[32];
    };

    enum class NHDFENBMHPA_GAGCILANNJC__Enum : int32_t {
        Invalid = 0x00000000,
        Queuing = 0x00000001,
        EnterScene = 0x00000002,
        ShowLoadingPage = 0x00000003,
        WaitingPeerID = 0x00000004,
        SceneReady = 0x00000005,
        InitScene = 0x00000006,
        LoadStage = 0x00000007,
        SceneInitFinish = 0x00000008,
        SceneDone = 0x00000009,
        LoadingFinish = 0x0000000a,
    };

    enum class NHDFENBMHPA_MOEOFNOOJDP__Enum : int32_t {
        Invalid = 0x00000000,
        Scene = 0x00000001,
        Dungeon = 0x00000002,
        Goto = 0x00000003,
    };

    struct __declspec(align(8)) NHDFENBMHPA__Fields {
        NHDFENBMHPA_GAGCILANNJC__Enum stage;
        NHDFENBMHPA_MOEOFNOOJDP__Enum eventType;
        uint32_t AJILLILMGOK;
        uint32_t HCEFFGIAGAL;
        uint32_t JKJOFMDGFOC;
        struct Vector3 OAHPGCJNKEG;
        bool MKMJCOFPIBC;
        bool GBDNPJKAAEG;
        bool FLMFNLGMMEB;
        uint32_t DGLHAGFCIDA;
        uint32_t GBJJEFLIFGH;
        uint64_t DPCBAMGCCII;
        struct String* DGJJIGNGDID;
        void* FNGCPOCIAII;
    };

    struct NHDFENBMHPA {
        struct NHDFENBMHPA__Class* klass;
        MonitorData* monitor;
        struct NHDFENBMHPA__Fields fields;
    };

    struct NHDFENBMHPA__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct NHDFENBMHPA* vector[32];
    };

    struct __declspec(align(8)) Dictionary_2_System_UInt32_NHDFENBMHPA___Fields {
        struct Int32__Array* table;
        struct Link__Array* linkSlots;
        struct UInt32__Array* keySlots;
        struct NHDFENBMHPA__Array* valueSlots;
        int32_t touchedSlots;
        int32_t emptySlot;
        int32_t count;
        int32_t threshold;
        void* hcp;
        void* serialization_info;
        int32_t generation;
    };

    struct Dictionary_2_System_UInt32_NHDFENBMHPA_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_UInt32_NHDFENBMHPA___Fields fields;
    };

    struct Vector_1__Fields {
        struct MessageBase_1__Fields _;
        float x;
        float y;
        float z;
    };

    struct Vector_1 {
        void* klass;
        MonitorData* monitor;
        struct Vector_1__Fields fields;
    };

    struct __declspec(align(8)) HNNKHOOAPAC_System_UInt32___Fields {
        struct UInt32__Array* COJDHBJAFNE;
        int32_t OHALFFMCMLN;
    };

    struct HNNKHOOAPAC_System_UInt32_ {
        void* klass;
        MonitorData* monitor;
        struct HNNKHOOAPAC_System_UInt32___Fields fields;
    };

    struct PlayerEnterSceneNotify__Fields {
        struct MessageBase_1__Fields  _;
        uint32_t sceneId_;
        struct Vector_1* pos_;
        uint64_t sceneBeginTime_;
        EnterType__Enum type_;
        uint32_t targetUid_;
        uint32_t prevSceneId_;
        struct Vector_1* prevPos_;
        uint32_t dungeonId_;
        uint32_t worldLevel_;
        uint32_t enterSceneToken_;
        bool isFirstLoginEnterScene_;
        struct Google_Protobuf_Collections_RepeatedPrimitiveField_1_System_UInt32_* sceneTagIdList_;
        bool isSkipUi_;
        uint32_t enterReason_;
        uint32_t worldType_;
        struct String* sceneTransaction_;
    };

    struct PlayerEnterSceneNotify {
        void* klass;
        MonitorData* monitor;
        struct PlayerEnterSceneNotify__Fields fields;
    };

    struct __declspec(align(8)) LoadingManager__Fields {
        struct Dictionary_2_System_UInt32_LoadingTask_* _loadingTasks;
        struct LoadingTask* _curLoadingTask;
        struct LoadingTask* _lastLoadingTask;
        struct BornTask* _bornTask;
        struct Coroutine* _bornCoroutine;
        struct Action_1_ILuaActor_* _transPreCallback;
        struct Action_1_ILuaActor_* _transFinishCallback;
        struct ILuaActor* _curActor;
        struct Vector3 _cacheJumpPos;
        EnterType__Enum _cacheEnterType;
        uint32_t _cacheToken;
        bool _cacheIsSkipUI;
        bool _isPlayerTransStart;
        uint32_t _enterReaon;
        struct Coroutine* _delayTransmitInCSCoroutine;
    };

    struct MoleMole_LoadingManager {
        struct LoadingManager__Class* klass;
        MonitorData* monitor;
        struct LoadingManager__Fields fields;
    };

    enum class EvtTransmitAvatar_EvtTransmitAvatar_TransmitType__Enum : int32_t {
        Default = 0x00000000,
        Wormhole = 0x00000001,
        Quick = 0x00000002,
        DirectlySetPos = 0x00000003,
        QuickWithoutPaimonReminder = 0x00000004,
    };

    enum class MoleMole_NotifyTypes__Enum : int32_t {
        None = 0x00000000,
        NetworkPacket = 0x00000001,
        LoginNotify = 0x00000002,
        EnterSceneNotify = 0x00000003,
        DisConnectNotify = 0x00000004,
        PlayerListNotify = 0x00000005,
        PlayerLeaveNotify = 0x00000006,
        GetOnlinePlayerInfoNotify = 0x00000007,
        WorldPlayerListUpdate = 0x00000008,
        PrompStandy2Climb = 0x00000009,
        RegisterMonsterAIController = 0x0000000a,
        AttackDamegeNotify = 0x0000000b,
        AttackShieldNotify = 0x0000000c,
        AttackCureNotify = 0x0000000d,
        RefreshAvatarData = 0x0000000e,
        RefreshAvatarBuff = 0x0000000f,
        AvatarChangeNotify = 0x00000010,
        AvatarActionPanelNotify = 0x00000011,
        AvatarFocusModeChangeNotify = 0x00000012,
        ElementReactionNotify = 0x00000013,
        OnApplicationFocus = 0x00000014,
        AvatarSkillInfoUpdate = 0x00000015,
        AddMiniMapMark = 0x00000016,
        MapNotify = 0x00000017,
        MapToggle = 0x00000018,
        EnterArea = 0x00000019,
        EnterSubArea = 0x0000001a,
        ExitSubArea = 0x0000001b,
        EnterErosionArea = 0x0000001c,
        MapMarkChanged = 0x0000001d,
        MapMarkMoved = 0x0000001e,
        MapMarkDailyTaskChanged = 0x0000001f,
        MapMarkDungeonEntryExploreChanged = 0x00000020,
        AreaExploreUpdated = 0x00000021,
        AreaUnlcoked = 0x00000022,
        GuidePointAppear = 0x00000023,
        GuidePointDisappear = 0x00000024,
        NavigationPointAppear = 0x00000025,
        NavigationPointDisappear = 0x00000026,
        NavigationPointRefresh = 0x00000027,
        NavigationShowGuideTips = 0x00000028,
        PlayMarkUnlockEffect = 0x00000029,
        UnlockTransPoint = 0x0000002a,
        UnlockScenePoint = 0x0000002b,
        AddGadgetIndicator = 0x0000002c,
        RemoveGadgetIndicator = 0x0000002d,
        SetGadgetIndicatorCountDown = 0x0000002e,
        MapMarkClicked = 0x0000002f,
        MapMarkClickNeared = 0x00000030,
        RefreshMapRewardTips = 0x00000031,
        RefreshMapMarkTips = 0x00000032,
        MapAreaUpdated = 0x00000033,
        PlaceNameUpdated = 0x00000034,
        MarkManagerReady = 0x00000035,
        DungeonEntryInfo = 0x00000036,
        DungeonEntryAppeared = 0x00000037,
        DungeonEntryDisappeared = 0x00000038,
        DungeonPlayerDie = 0x00000039,
        DungeonSettled = 0x0000003a,
        DungeonGetReward = 0x0000003b,
        GetDailyDungeonEntryInfo = 0x0000003c,
        GetDungeonEntryExploreCondition = 0x0000003d,
        GeneralInteeCreate = 0x0000003e,
        GeneralInteeCommand = 0x0000003f,
        RegisterUICombatBar = 0x00000040,
        UnregisterUICombatBar = 0x00000041,
        RefreshUICombatBars = 0x00000042,
        ShowUICombatBarSpark = 0x00000043,
        ShowUICombatBarCharge = 0x00000044,
        ShowUICombatBarFireEffect = 0x00000045,
        ShowShakeOff = 0x00000046,
        InteractionUITrigger = 0x00000047,
        InteractionUIClose = 0x00000048,
        InteractionRealStart = 0x00000049,
        GroupLinkUpdated = 0x0000004a,
        ChallengeBegin = 0x0000004b,
        ChallengeUpdated = 0x0000004c,
        ChallengeFailed = 0x0000004d,
        ChallengeCompleted = 0x0000004e,
        ChallengeAddSub = 0x0000004f,
        ChallengeSubFinish = 0x00000050,
        ChallengeSubFail = 0x00000051,
        DialogSelectNotify = 0x00000052,
        DialogSelectFinishNotify = 0x00000053,
        DialogSelectItemNotify = 0x00000054,
        DialogSelectItemTimeOut = 0x00000055,
        AutoTalkDialogFinish = 0x00000056,
        ChangeAutoTalk = 0x00000057,
        CoopSelectNotify = 0x00000058,
        CurrCoopConfidenceValueChanged = 0x00000059,
        CurrCoopTemperamentValueChanged = 0x0000005a,
        CoopTemperamentSelect = 0x0000005b,
        CoopTakeChapterReward = 0x0000005c,
        CoopUnlockChapter = 0x0000005d,
        CoopStartPointFromPage = 0x0000005e,
        CoopCancelQuest = 0x0000005f,
        CoopUIRefresh = 0x00000060,
        CoopChapterViewed = 0x00000061,
        CoopStartFirstPoint = 0x00000062,
        CoopShowDefeatDialog = 0x00000063,
        CoopTryStartPoint = 0x00000064,
        CoopStartPointFailed = 0x00000065,
        CoopDefeatNotify = 0x00000066,
        QuestDialogToggle = 0x00000067,
        QuestBookUpdate = 0x00000068,
        QuestBookSelectItem = 0x00000069,
        AddQuestHint = 0x0000006a,
        QuestTalkHistory = 0x0000006b,
        PaimenNavigationEnabled = 0x0000006c,
        PaimenNavigationFailed = 0x0000006d,
        PaimenNavigationAlreadyInArea = 0x0000006e,
        RemindQuest = 0x0000006f,
        BindTransButton = 0x00000070,
        QuestProgressHint = 0x00000071,
        QuestLackHint = 0x00000072,
        ActiveMainQuestDeleted = 0x00000073,
        QuestStateUpdated = 0x00000074,
        MainQuestStateUpdated = 0x00000075,
        QuestTalkFinished = 0x00000076,
        QuestGlobalVarUpdate = 0x00000077,
        QuestTakePhotograph = 0x00000078,
        BagWeightUIRefresh = 0x00000079,
        BagDialogToggle = 0x0000007a,
        BagSlotUpdate = 0x0000007b,
        BagItemUsed = 0x0000007c,
        BagItemDrop = 0x0000007d,
        BagAddChest = 0x0000007e,
        BagAddWidget = 0x0000007f,
        BagCombinableMaterialRPChanged = 0x00000080,
        ForceCloseBagPage = 0x00000081,
        BagItemDeleteReturnNotify = 0x00000082,
        NewItemEncountered = 0x00000083,
        SpecialItemEncountered = 0x00000084,
        ItemAdded = 0x00000085,
        MaterialDeleteReturnItemAdded = 0x00000086,
        ItemAddExceedLimitNotify = 0x00000087,
        GatherItemAdded = 0x00000088,
        GeneralItemAdded = 0x00000089,
        GeneralItemMiddleShowAdded = 0x0000008a,
        QuestItemAdded = 0x0000008b,
        DailyTaskItemAdded = 0x0000008c,
        RandTaskItemAdded = 0x0000008d,
        ActivityItemAdded = 0x0000008e,
        HuntingItemAdded = 0x0000008f,
        BlossomItemAdded = 0x00000090,
        VirtualShopItemAdded = 0x00000091,
        ItemGivingFinish = 0x00000092,
        CloseItemGiving = 0x00000093,
        DestroyItemFinish = 0x00000094,
        GetCalcWeaponUpgradeReturnItemsResult = 0x00000095,
        ChangeEquipLockState = 0x00000096,
        UseItemFail = 0x00000097,
        AvatarVehicleStateChange = 0x00000098,
        VehicleHPChange = 0x00000099,
        VehicleLevelChange = 0x0000009a,
        AvatarInfoUIRefresh = 0x0000009b,
        AvatarFightPropRefresh = 0x0000009c,
        AvatarEquipUIRefresh = 0x0000009d,
        AvatarEquipChanged = 0x0000009e,
        AvatarSwitch = 0x0000009f,
        ManekinCtrl = 0x000000a0,
        TeamInfoRefresh = 0x000000a1,
        TeamNameRefresh = 0x000000a2,
        CurrentTeamChanged = 0x000000a3,
        AvatarDead = 0x000000a4,
        AvatarSkillDepotIdChanged = 0x000000a5,
        AvatarBreakLevelChanged = 0x000000a6,
        AvatarBreakRewardGet = 0x000000a7,
        RefreshBreachMaterialBtnRPShow = 0x000000a8,
        AvatarLifeStateChanged = 0x000000a9,
        AvatarFetterExpChanged = 0x000000aa,
        AvatarFetterRewardGet = 0x000000ab,
        AvatarHPChanged = 0x000000ac,
        AvatarHungerChanged = 0x000000ad,
        BackgroundAvatarRefreshed = 0x000000ae,
        AvatarUpgradeNotify = 0x000000af,
        AvatarLevelChanged = 0x000000b0,
        AvatarEnergyAdded = 0x000000b1,
        AvatarEnergyFull = 0x000000b2,
        CharacterSprintBS = 0x000000b3,
        AvatarSkillChanged = 0x000000b4,
        AvatarSkillDisable = 0x000000b5,
        AvatarSkillCDChanged = 0x000000b6,
        AvatarSkillEnable = 0x000000b7,
        AvatarHideSkill = 0x000000b8,
        CurAvatarNum = 0x000000b9,
        FocusAvatar = 0x000000ba,
        AvatarFlycloakChanged = 0x000000bb,
        AvatarGainFlycloak = 0x000000bc,
        ActivitySkillState = 0x000000bd,
        ShowActivitySkill = 0x000000be,
        AvatarCostumeChanged = 0x000000bf,
        AvatarGainCostume = 0x000000c0,
        TipShow = 0x000000c1,
        TipClose = 0x000000c2,
        ActivityCommonPlayerTipsStart = 0x000000c3,
        ActivityCommonPlayerTipsFinish = 0x000000c4,
        ActivityCommonPlayerTipsFail = 0x000000c5,
        ShopOpen = 0x000000c6,
        ShopClose = 0x000000c7,
        ShopItemSelect = 0x000000c8,
        ShopRefresh = 0x000000c9,
        ShopMaterialRefresh = 0x000000ca,
        ShopRequest = 0x000000cb,
        ShopRequestRecommend = 0x000000cc,
        ShopRequestPackage = 0x000000cd,
        ShopMallRequest = 0x000000ce,
        ShopDataUpdated = 0x000000cf,
        ActivityShopSheetUpdated = 0x000000d0,
        ShopOpenSubTab = 0x000000d1,
        MallJumpRecommend = 0x000000d2,
        ActivityRegionSearchProgressUpdate = 0x000000d3,
        ActivityRegionSearchProgressBegin = 0x000000d4,
        ActivityRegionSearchProgressComplete = 0x000000d5,
        ActivityRegionSearchIn = 0x000000d6,
        ActivityRegionSearchOut = 0x000000d7,
        ActivityRegionSearchRegionRewardGet = 0x000000d8,
        ActivityRegionSearchRegionDisappear = 0x000000d9,
        ActivityRegionSearchRegionAppear = 0x000000da,
        ActivityRegionSearchRegionInfoUpdate = 0x000000db,
        CountDownUIStart = 0x000000dc,
        CountDownUITerminate = 0x000000dd,
        DungeonCountDownUpdate = 0x000000de,
        DungeonCountDownEnd = 0x000000df,
        CountNumUIStart = 0x000000e0,
        CountNumUpdate = 0x000000e1,
        CountNumUITerminate = 0x000000e2,
        CountNumUIStartNew = 0x000000e3,
        CountNumUpdateNew = 0x000000e4,
        CountNumUITerminateNew = 0x000000e5,
        QuestQuitShow = 0x000000e6,
        QuestQuitHide = 0x000000e7,
        GachaWishUpdate = 0x000000e8,
        LoadingNewScenePre = 0x000000e9,
        LoadingScene = 0x000000ea,
        LevelPreLoaded = 0x000000eb,
        LevelLoaded = 0x000000ec,
        LevelPostLoad = 0x000000ed,
        LevelLoadBegin = 0x000000ee,
        LoadingBundle = 0x000000ef,
        LevelLoadFinish = 0x000000f0,
        NoStaminaStopSprint = 0x000000f1,
        JumpFly = 0x000000f2,
        PostAvatarEntityReady = 0x000000f3,
        AudioEventPost = 0x000000f4,
        LevelTagNotify = 0x000000f5,
        TouchMsgBoard = 0x000000f6,
        EasyTouchWorking = 0x000000f7,
        RefreshUISetting = 0x000000f8,
        ScreenResolutionChanged = 0x000000f9,
        RefreshAvatarTalent = 0x000000fa,
        RefreshAvatarTalentPRShow = 0x000000fb,
        Resist = 0x000000fc,
        GuideUpdate = 0x000000fd,
        PageLoad = 0x000000fe,
        UIContextOpen = 0x000000ff,
        UIContextClose = 0x00000100,
        PageDestroy = 0x00000101,
        ElementViewChange = 0x00000102,
        SealProgress = 0x00000103,
        CommonChallengeStartTips = 0x00000104,
        CommonChallengeEndTips = 0x00000105,
        RefreshGuide = 0x00000106,
        GeneralGuideFinish = 0x00000107,
        RefreshDebugUI = 0x00000108,
        CheckDebugLoginServerList = 0x00000109,
        ShowDebugLoginPanel = 0x0000010a,
        TimeChanged = 0x0000010b,
        PlayerGameTimeNotify = 0x0000010c,
        TeamSceneReady = 0x0000010d,
        TeamChanged = 0x0000010e,
        AvatarReviveRequested = 0x0000010f,
        TeamRttRefresh = 0x00000110,
        ShowTeamBtn = 0x00000111,
        LevelUpItemFinished = 0x00000112,
        PostSetupMPTeamPanel = 0x00000113,
        WeaponUpgrade = 0x00000114,
        WeaponPromote = 0x00000115,
        WeaponAwaken = 0x00000116,
        ReliquaryUpgrade = 0x00000117,
        ReliquaryPromote = 0x00000118,
        TeammateSpeechBegin = 0x00000119,
        TeammateSpeechEnd = 0x0000011a,
        AvatarCardChange = 0x0000011b,
        SpringVolumeChanged = 0x0000011c,
        WebviewClose = 0x0000011d,
        MihoyoAccountInfoChanged = 0x0000011e,
        MihoyoAccountRegisterSuccess = 0x0000011f,
        CutsceneStart = 0x00000120,
        CutsceneFinish = 0x00000121,
        FinalTalkFinished = 0x00000122,
        CutsceneQTEJump = 0x00000123,
        CurrentQTEGiveUp = 0x00000124,
        CurrentQTEBlackScreenStart = 0x00000125,
        CutsceneQTEEnableSavePoint = 0x00000126,
        CutsceneQTEEnableSavePointId = 0x00000127,
        CutsceneChangeTimeScale = 0x00000128,
        CutsceneResumeTimeScale = 0x00000129,
        SetMainPageMoveToggleActive = 0x0000012a,
        SetMainPageMoveToggleToWalk = 0x0000012b,
        OpenStateInit = 0x0000012c,
        OpenStateChange = 0x0000012d,
        StartFadeOutWormhole = 0x0000012e,
        EnterSneakMode = 0x0000012f,
        ExitSneakMode = 0x00000130,
        PlayModeChange = 0x00000131,
        RefreshCookPage = 0x00000132,
        GetCookQTEArgs = 0x00000133,
        OnCookRecipeDataNotify = 0x00000134,
        RefreshCookCompoundPage = 0x00000135,
        GetCompoundOutput = 0x00000136,
        GetCombineOutput = 0x00000137,
        CombineFormulaUnlock = 0x00000138,
        SmeltSuccess = 0x00000139,
        SmeltGetDrop = 0x0000013a,
        GetForgeQueue = 0x0000013b,
        ForgeQueueUpdate = 0x0000013c,
        GetForgeOutput = 0x0000013d,
        ForgeStart = 0x0000013e,
        ForgeStop = 0x0000013f,
        ForgeFormulaUnlock = 0x00000140,
        RefreshMailPage = 0x00000141,
        RefreshMailPageAfterDel = 0x00000142,
        MailDataReady = 0x00000143,
        ShowMailItemGet = 0x00000144,
        NewMailGot = 0x00000145,
        AddToFavorites = 0x00000146,
        RefreshMailFavoritesDialog = 0x00000147,
        RefreshMailFavoritesDialogAfterDel = 0x00000148,
        RefreshMailPageAfterFavMailChange = 0x00000149,
        RefreshCoinNum = 0x0000014a,
        MutiPlayerAvailableChange = 0x0000014b,
        MutiPlayerModeChange = 0x0000014c,
        CompanionCurrAvatarChanged = 0x0000014d,
        CompanionAvatarHPChanged = 0x0000014e,
        KickGuestFailed = 0x0000014f,
        MPTeamChangeFailed = 0x00000150,
        MPDeathOpenChat = 0x00000151,
        MPCloseMainPageBtn = 0x00000152,
        MPOpenMainPageBtn = 0x00000153,
        PlayerMatchInfoUpdate = 0x00000154,
        WorldPlayerDie = 0x00000155,
        MpSettingType = 0x00000156,
        JoinOtherPlayerScene = 0x00000157,
        BackMyWorld = 0x00000158,
        UpdateDungeonExitBtn = 0x00000159,
        DungeonTeamChanged = 0x0000015a,
        DungeonTeamChangeFailed = 0x0000015b,
        DungeonTeamDismissed = 0x0000015c,
        DungeonInviteRefused = 0x0000015d,
        DungeonTeamKicked = 0x0000015e,
        EnterTowerLevel = 0x0000015f,
        TowerStarRefresh = 0x00000160,
        TowerRecordHandbookRefresh = 0x00000161,
        RefreshPlayGuestState = 0x00000162,
        CloseMPPlayDialog = 0x00000163,
        CloseMPPlayPage = 0x00000164,
        MpPlayGuestReplyInviteSucc = 0x00000165,
        PlayerLevelChange = 0x00000166,
        PlayerExpChange = 0x00000167,
        PlayerWorldLevelChange = 0x00000168,
        ClosePlayerProfilePage = 0x00000169,
        PlayerWorldLevelAdjust = 0x0000016a,
        ShowGuideRatingDialog = 0x0000016b,
        ChargeBarValueChange = 0x0000016c,
        DailyTaskStarted = 0x0000016d,
        DailyTaskProgresUpdated = 0x0000016e,
        DailyTaskComplete = 0x0000016f,
        DailyTaskExitRegion = 0x00000170,
        DailyTaskScoreReward = 0x00000171,
        DailyTaskRefresh = 0x00000172,
        TaskVarChange = 0x00000173,
        RandTaskStarted = 0x00000174,
        RandTaskComplete = 0x00000175,
        RandTaskFail = 0x00000176,
        RandTaskExitRegion = 0x00000177,
        RoutineStarted = 0x00000178,
        RoutineProgresUpdated = 0x00000179,
        RoutineComplete = 0x0000017a,
        RoutineExitRegion = 0x0000017b,
        RoutineScoreReward = 0x0000017c,
        RoutineRefresh = 0x0000017d,
        ProudSkillChange = 0x0000017e,
        CombatSkillChange = 0x0000017f,
        PlayerLevelRewardChange = 0x00000180,
        GetInvestigationMonsterList = 0x00000181,
        InvestigationChange = 0x00000182,
        InvestigationChapterComplete = 0x00000183,
        InvestigationTargetChange = 0x00000184,
        ExplorationAllDataChange = 0x00000185,
        ExplorationCharacterDataChange = 0x00000186,
        MainPageTips = 0x00000187,
        MiracleRingItemAdded = 0x00000188,
        NewPlayerAppling = 0x00000189,
        PushTipsChange = 0x0000018a,
        GetPushTipsReward = 0x0000018b,
        PushTipsNotifyFinish = 0x0000018c,
        NewPushTips = 0x0000018d,
        GetTowerAllData = 0x0000018e,
        GetTowerStarReward = 0x0000018f,
        VersusBattleBegin = 0x00000190,
        VersusBattleUpdate = 0x00000191,
        VersusBattleEnd = 0x00000192,
        ActivityOpen = 0x00000193,
        ActivityClose = 0x00000194,
        ActivityContextClose = 0x00000195,
        ActivityRefresh = 0x00000196,
        ActivityUpdate = 0x00000197,
        ActivityBannerShow = 0x00000198,
        ActivityBannerEffectShow = 0x00000199,
        ActivitySeaLampContriFinish = 0x0000019a,
        ActivityStart = 0x0000019b,
        ActivityCrucibleInfo = 0x0000019c,
        ActivityOperationBonusUpdate = 0x0000019d,
        ActivityWatcherUpdate = 0x0000019e,
        ActivityDeliveryRewardUpdate = 0x0000019f,
        ActivityDeliveryUpdate = 0x000001a0,
        ActivityWatcherFinish = 0x000001a1,
        ActivityAsterScoreUpdate = 0x000001a2,
        ActivitySaleUpdate = 0x000001a3,
        ActivityEchoShellUpdate = 0x000001a4,
        ActivityCoinInfoNotify = 0x000001a5,
        ActivityBlitzRushContentClose = 0x000001a6,
        ActivityCondUpdate = 0x000001a7,
        ActivityPotionStageReset = 0x000001a8,
        CloseActivityMainPage = 0x000001a9,
        EffigyChallengeResultNotify = 0x000001aa,
        MistTrialTimeOutNotify = 0x000001ab,
        BannerReminderAppeared = 0x000001ac,
        BannerReminderDisappeared = 0x000001ad,
        InLevelQuestHintReminderAppeared = 0x000001ae,
        InLevelQuestHintReminderDisappeared = 0x000001af,
        OnGetGameplayRecommendationNotify = 0x000001b0,
        CloseRecommendationNotify = 0x000001b1,
        OnGetGameplayRecommendationFailedNotify = 0x000001b2,
        CameraLookBegin = 0x000001b3,
        CameraLock = 0x000001b4,
        CameraFieldLook = 0x000001b5,
        DisableMainPageControl = 0x000001b6,
        DisableMainPageControlWithConfigName = 0x000001b7,
        ResinChanged = 0x000001b8,
        ResinPurchased = 0x000001b9,
        BlossomBriefInfoNotify = 0x000001ba,
        BlossomStart = 0x000001bb,
        BlossomUpdate = 0x000001bc,
        BlossomEnd = 0x000001bd,
        BlossomFinish = 0x000001be,
        ShowDamageTextComponent = 0x000001bf,
        SinInRefresh = 0x000001c0,
        OnSignInInfoRsp = 0x000001c1,
        BonusActivityRewardRsp = 0x000001c2,
        ShowActivityMainBtn = 0x000001c3,
        OnBonusActivityInfoRsp = 0x000001c4,
        OnOpActivityStateRsp = 0x000001c5,
        OnOpActivityStateNotify = 0x000001c6,
        TrialActivityRewardUpdate = 0x000001c7,
        SalesManTakeRewardRsp = 0x000001c8,
        SalesmanDeliverItemRsp = 0x000001c9,
        GetAuthSalesmanInfoRsp = 0x000001ca,
        OnVirtualDialAction = 0x000001cb,
        OnVirtualDialEntryAction = 0x000001cc,
        OnTransmitStart = 0x000001cd,
        OnTransmitEnd = 0x000001ce,
        OnTransmitAfterAudioEvent = 0x000001cf,
        BundleDownloadStart = 0x000001d0,
        BundleDownloadRestart = 0x000001d1,
        BundleDownloadStartForLogin = 0x000001d2,
        BargainStart = 0x000001d3,
        BargainPriceRsp = 0x000001d4,
        BargainTerminate = 0x000001d5,
        BargainDataRsp = 0x000001d6,
        AllActivatedBargainData = 0x000001d7,
        HideRoom = 0x000001d8,
        ShowRoom = 0x000001d9,
        DeleteFriend = 0x000001da,
        RefreshFriendList = 0x000001db,
        RefreshFriendListWithAni = 0x000001dc,
        RefreshFriendRequestList = 0x000001dd,
        RefreshFriendRequestListWithAni = 0x000001de,
        RefreshBlacklist = 0x000001df,
        RefreshMultiplayRecentlyListWithAni = 0x000001e0,
        RefreshPSNFriendList = 0x000001e1,
        RefreshPSNFriendListWithAni = 0x000001e2,
        GetPlayerSocialDetail = 0x000001e3,
        GetFriendShowAvatarInfo = 0x000001e4,
        RefreshNickname = 0x000001e5,
        RefreshRemarkname = 0x000001e6,
        RefreshHeadPortrait = 0x000001e7,
        RefreshNameCard = 0x000001e8,
        RefreshAllNameCard = 0x000001e9,
        RefreshSignature = 0x000001ea,
        RefreshAvatarShowList = 0x000001eb,
        RefreshNameCardShowList = 0x000001ec,
        NicknameWordIllegal = 0x000001ed,
        TeamNameIllegal = 0x000001ee,
        SignatureIllegal = 0x000001ef,
        RefreshBirthday = 0x000001f0,
        AddInBlockChatList = 0x000001f1,
        RemoveFromBlockChatList = 0x000001f2,
        AddInBlacklist = 0x000001f3,
        RemoveFromBlacklist = 0x000001f4,
        ChatRoomInfoUpdate = 0x000001f5,
        RefreshMainPageChatContent = 0x000001f6,
        RefreshMainPageChatContentForce = 0x000001f7,
        RefreshChatEmojiCollectionList = 0x000001f8,
        BattlePassMissionChange = 0x000001f9,
        BattlePassScheduleChange = 0x000001fa,
        BattlePassProductPay = 0x000001fb,
        BattlePassLevelChange = 0x000001fc,
        BattlePassBuySuccess = 0x000001fd,
        RefreshLocalNotification = 0x000001fe,
        EnterSceneDone = 0x000001ff,
        PSNStateChange = 0x00000200,
        PS5LaunchActivity = 0x00000201,
        MpPlayPrepareNotify = 0x00000202,
        GadgetPlayStartNotify = 0x00000203,
        GadgetPlayDataNotify = 0x00000204,
        GadgetPlayUidOpNotify = 0x00000205,
        GadgetPlayStopNotify = 0x00000206,
        GadgetChainChangeNotify = 0x00000207,
        ScenePlayBattlePrepare = 0x00000208,
        ScenePlayBattlePrestart = 0x00000209,
        ScenePlayBattleStart = 0x0000020a,
        ScenePlayBattleStop = 0x0000020b,
        ScenePlayBattleInterrupt = 0x0000020c,
        ScenePlayUidOpNotify = 0x0000020d,
        StartChargeCountDown = 0x0000020e,
        InterruptChargeCountDown = 0x0000020f,
        ShowTemplateReminderNotify = 0x00000210,
        CloseTemplateReminderDialog = 0x00000211,
        ShowPromptDownReminderNotify = 0x00000212,
        NormalUidOpNotify = 0x00000213,
        OnDispatchConfigSet = 0x00000214,
        ShowDistanceTarget = 0x00000215,
        CloseDistanceTarget = 0x00000216,
        ClimateMeterType = 0x00000217,
        ClimateMeterValue = 0x00000218,
        ClimateAreaType = 0x00000219,
        ClimateAreaID = 0x0000021a,
        ClimateMeterValueChanged = 0x0000021b,
        ClimateMeterTypeChanged = 0x0000021c,
        ClimateAreaTypeChanged = 0x0000021d,
        ClimateMeterWarning = 0x0000021e,
        ClimateMeterRefresh = 0x0000021f,
        ShowClimateInfoDialog = 0x00000220,
        DungeonFactorDialogClose = 0x00000221,
        ShowMonthlyCardReward = 0x00000222,
        AchievementPageRefresh = 0x00000223,
        AchievementItemAdded = 0x00000224,
        RefreshAvatarLinePage = 0x00000225,
        OnPersonalLineAllDataRsp = 0x00000226,
        AvatarLineGetKey = 0x00000227,
        AvatarLineUnlock = 0x00000228,
        ShareComplete = 0x00000229,
        SDKPayStart = 0x0000022a,
        SDKPayEnd = 0x0000022b,
        SDKGetProductList = 0x0000022c,
        AvatarAddNotify = 0x0000022d,
        TrialAvatarDelete = 0x0000022e,
        OnTakeReputationLevelReward = 0x0000022f,
        RefreshReputation = 0x00000230,
        OnCityReputationLevelup = 0x00000231,
        RefreshHunting = 0x00000232,
        HuntingStart = 0x00000233,
        HuntingRevealClue = 0x00000234,
        HuntingRevealFinal = 0x00000235,
        HuntingSuccess = 0x00000236,
        HuntingFail = 0x00000237,
        CloseReputationHuntingDialog = 0x00000238,
        CloseReputationRequestDialog = 0x00000239,
        HuntingTaken = 0x0000023a,
        HuntingFinished = 0x0000023b,
        TakeOfferingLevelReward = 0x0000023c,
        OfferingLevelChange = 0x0000023d,
        OfferingLevelChangeReward = 0x0000023e,
        ForbiddenToggleMoveStateChange = 0x0000023f,
        OnToggleMoveSettingChange = 0x00000240,
        KeyboardLayoutUpdate = 0x00000241,
        ControllerMapModified = 0x00000242,
        OnControllerConnected = 0x00000243,
        OnDeviceTypeSet = 0x00000244,
        SetDeviceTypeInSettingPage = 0x00000245,
        OnJoypadIconDisplayTypeChange = 0x00000246,
        WidgetActionBtnRefresh = 0x00000247,
        WidgetEquipChange = 0x00000248,
        WidgetCollectorWindSeed = 0x00000249,
        WidgetQuickUseButtonRelease = 0x0000024a,
        WidgetQuickUseRsp = 0x0000024b,
        ForcePlayBattleBtnCdEndEffect = 0x0000024c,
        FlightChallengeBegin = 0x0000024d,
        FlightChallengeFinish = 0x0000024e,
        ReportSuccNotify = 0x0000024f,
        PlayerQuitFromMpByHostBlock = 0x00000250,
        PlayerQuitFromMpByGuestBlock = 0x00000251,
        ActivityBlessingDataRefresh = 0x00000252,
        ActivityBlessingScanSuccess = 0x00000253,
        ActivityBlessingScanFail = 0x00000254,
        ActivityBlessingRefresh = 0x00000255,
        ActivityGiveFriendPicSuccess = 0x00000256,
        TreasureHuntCurrencyNumChange = 0x00000257,
        ReunionAddToOpActivityListNotify = 0x00000258,
        ReunionRemoveFromOpActivityListNotify = 0x00000259,
        ReunionGetFirstRewardSuccNotify = 0x0000025a,
        ReunionSignInGetRewardNotify = 0x0000025b,
        ReunionTaskClaimFinalRewardSuccNotify = 0x0000025c,
        ReunionTaskClaimWatcherRewardSuccNotify = 0x0000025d,
        AvatarExpeditionStartNtf = 0x0000025e,
        ShowLendHistoryNotify = 0x0000025f,
        ExpeditionActivityStartNotify = 0x00000260,
        ExpeditionActivityRecallNotify = 0x00000261,
        ExpeditionActivityRewardClaimedNotify = 0x00000262,
        ExpeditionActivityInfoUpdateNotify = 0x00000263,
        OpenExpeditionMap = 0x00000264,
        OnExpeditionChallengeEnterRegion = 0x00000265,
        OnExpeditionChallengeFinish = 0x00000266,
        GetExpeditionRewardNotify = 0x00000267,
        GadgetGroupButtonAddNotify = 0x00000268,
        GadgetGroupButtonRemoveNotify = 0x00000269,
        ActivityUpdateRegion = 0x0000026a,
        WalkModeChanged = 0x0000026b,
        FireUIEffectNotify = 0x0000026c,
        AttachUIEffectNotify = 0x0000026d,
        UntachUIEffectNotify = 0x0000026e,
        PlayerApplyEnterMpResult = 0x0000026f,
        PlayerQuitFromMp = 0x00000270,
        PlayerVehilceUpdate = 0x00000271,
        UpdateFriendsWishNotify = 0x00000272,
        UpdateRecvGiftsNotify = 0x00000273,
        UpdateGiftRecvInfoNotify = 0x00000274,
        UpdateGiveGiftDialog = 0x00000275,
        HaveRecvGiftNotify = 0x00000276,
        GachaActivityPercentNotify = 0x00000277,
        GachaActivityCreateRobotRsp = 0x00000278,
        GachaActivityResetRsp = 0x00000279,
        GachaActivityTakeRewardRsp = 0x0000027a,
        GachaActivityNextStageRsp = 0x0000027b,
        GetMechanicusInfoRsp = 0x0000027c,
        UpdateGearItem = 0x0000027d,
        UnLockGearItem = 0x0000027e,
        FoundationOpLockFailed = 0x0000027f,
        MechanicusCoinNotify = 0x00000280,
        FoundationUpdateNotify = 0x00000281,
        OnInBattleMechanicusStageKillStartNotify = 0x00000282,
        OnInBattleMechanicusStageKillEndNotify = 0x00000283,
        OnInBattleMechanicusStageCardFlipEndNotify = 0x00000284,
        OnInBattleMechanicusStart = 0x00000285,
        OnInBattleMechanicusUpdate = 0x00000286,
        OnInBattleMechanicusFinish = 0x00000287,
        OnInBattleMechanicusPickCardRsp = 0x00000288,
        OnInBattleMechanicusPickCardNotify = 0x00000289,
        OnInBattleMechanicusConfirmCardRsp = 0x0000028a,
        OnInBattleMechanicusConfirmCardNotify = 0x0000028b,
        OnInBattleMechanicusCardResultNotify = 0x0000028c,
        OnInBattleChessPickCardNotify = 0x0000028d,
        OnInBattleChessCandidateCardsNotify = 0x0000028e,
        FleurFairDungeonPreview = 0x0000028f,
        FleurFairDungeonPrepare = 0x00000290,
        FleurFairDungeonGallery = 0x00000291,
        FleurFairDungeonBoss = 0x00000292,
        FleurFairDungeonGallerySettle = 0x00000293,
        FleurFairDungeonBossSettle = 0x00000294,
        FleurFairDungeonEnergy = 0x00000295,
        FleurFairDungeonGalleryUpdate = 0x00000296,
        SummerTimeStage4JoypadFocusChange = 0x00000297,
        SummerTimeSprintBoatRedpointChange = 0x00000298,
        GalleryDialogShow = 0x00000299,
        GalleryStart = 0x0000029a,
        GalleryStop = 0x0000029b,
        GalleryUpdateAll = 0x0000029c,
        GalleryBalloonShoot = 0x0000029d,
        GalleryBalloonScore = 0x0000029e,
        GalleryFallCatch = 0x0000029f,
        GalleryFallScore = 0x000002a0,
        GalleryMusicGameClose = 0x000002a1,
        GallerySettleRestart = 0x000002a2,
        SlabCheckEnterLoopDungeon = 0x000002a3,
        SlabEquipBuffChange = 0x000002a4,
        GallerySumoStageStart = 0x000002a5,
        GallerySumoStageFinish = 0x000002a6,
        GallerySumoChangeTeam = 0x000002a7,
        GallerySumoChangeTeamCdUpdate = 0x000002a8,
        GallerySumoChangeTeamUpdateScore = 0x000002a9,
        StartCrystalLinkGalleryNotify = 0x000002aa,
        UpdateCrystalLinkGalleryNotify = 0x000002ab,
        StopCrystalLinkGalleryNotify = 0x000002ac,
        CrystalLinkBuffUpdate = 0x000002ad,
        CrystalLinkBuffEffect = 0x000002ae,
        CrystalLinkBuffActiveNotify = 0x000002af,
        QuickSwitchTeamFetchNextTeamInfo = 0x000002b0,
        QuickSwitchTeamReqToChangeTeam = 0x000002b1,
        ArenaChallengeStart = 0x000002b2,
        ArenaChallengeTakeWatcherReward = 0x000002b3,
        ActivityMistTrialTakeReward = 0x000002b4,
        ActivityMistTrialExhibitionRefresh = 0x000002b5,
        ActivityMistTrialGalleryCountDown = 0x000002b6,
        ActivityMiniTomoClose = 0x000002b7,
        HomeWorldCompInfoUpdate = 0x000002b8,
        HomeWorldModuleChange = 0x000002b9,
        HomeWorldModuleChoose = 0x000002ba,
        HomeWorldModuleSeenUpdate = 0x000002bb,
        HomeWorldModulePrepareGoIn = 0x000002bc,
        HomeWorldFurnitureMakeInfoRefresh = 0x000002bd,
        HomeWorldFurnitureMakeGetResult = 0x000002be,
        HomeWorldFurnitureMakeCancel = 0x000002bf,
        HomeWorldFurnitureFormulaUnlock = 0x000002c0,
        HomeWorldLevelUp = 0x000002c1,
        HomeWorldSuiteDetailShow = 0x000002c2,
        GetHomeworldVisitor = 0x000002c3,
        HomeKickPlayerRspSuccess = 0x000002c4,
        HomeWorldComfortInfoUpdate = 0x000002c5,
        ClearDeployGadgetData = 0x000002c6,
        HomeWorldChangeBGM = 0x000002c7,
        HomeWorldUnlockBGM = 0x000002c8,
        HideAndSeekStagePrepare = 0x000002c9,
        HideAndSeekStagePick = 0x000002ca,
        HideAndSeekStageHide = 0x000002cb,
        HideAndSeekStageSeek = 0x000002cc,
        HideAndSeekPlayerSetAvatarNotify = 0x000002cd,
        HideAndSeekSelectSkillRsp = 0x000002ce,
        HideAndSeekPlayerReadyNotify = 0x000002cf,
        HideAndSeekStageSettle = 0x000002d0,
        HideAndSeekCaught = 0x000002d1,
        AvatarChargeSkillNotify = 0x000002d2,
        LoginSceneNotify = 0x000002d3,
        CharacterPageNotify = 0x000002d4,
        CloseCharacterPageNotify = 0x000002d5,
        WeaponPageNotify = 0x000002d6,
        CloseWeaponPageNotify = 0x000002d7,
        LoadingBeginNotify = 0x000002d8,
        LoadingEndNotify = 0x000002d9,
        GachaItemNotify = 0x000002da,
        CloseGachaNotify = 0x000002db,
        GoToGachaPageNotify = 0x000002dc,
        GrowFlowersUpdateTodaySeedNotify = 0x000002dd,
        GrowFlowersUpdateExchangePage = 0x000002de,
        GrowFlowersUpdateFriendsWishNotify = 0x000002df,
        GrowFlowersUpdateRecvFlowersNotify = 0x000002e0,
        GrowFlowersUpdateRecvInfo = 0x000002e1,
        GrowFlowersUpdateGiveDialog = 0x000002e2,
        WinterCampSnowmanUpdateFriendsWishNotify = 0x000002e3,
        WinterCampSnowmanUpdateRecvItemNotify = 0x000002e4,
        WinterCampSnowmanUpdateRecvInfo = 0x000002e5,
        WinterCampSnowmanUpdateGiveDialog = 0x000002e6,
        StartBuoyantCombatGallerySuccess = 0x000002e7,
        StartBuoyantCombatGalleryNotify = 0x000002e8,
        UpdateBuoyantCombatGalleryNotify = 0x000002e9,
        StopBuoyantCombatGalleryNotify = 0x000002ea,
        StartGalleryProgressNotify = 0x000002eb,
        UpdateGalleryProgressNotify = 0x000002ec,
        StopGalleryProgressNotify = 0x000002ed,
        StartDigCombatGalleryNotify = 0x000002ee,
        UpdateDigCombatGalleryNotify = 0x000002ef,
        StopDigCombatGalleryNotify = 0x000002f0,
        SalvagePreventUpdateNotify = 0x000002f1,
        SalvageEscortUpdateNotify = 0x000002f2,
        UpdateSalvageBundleMark = 0x000002f3,
        UpdateBounceConjuringScore = 0x000002f4,
        AddBounceConjuringScore = 0x000002f5,
        LunaRiteSacrificeSuccess = 0x000002f6,
        LunaRiteRefresh = 0x000002f7,
        MoonfinTrialWatcherUpdated = 0x000002f8,
        TryShowQTEDialog = 0x000002f9,
        EnableSubtitleInputPenetrate = 0x000002fa,
        CodexKillNumRefresh = 0x000002fb,
        FishBaitUpdate = 0x000002fc,
        FishQteStart = 0x000002fd,
        FishBattleEnd = 0x000002fe,
        ExitFishing = 0x000002ff,
        FishRippleEffectStart = 0x00000300,
        FishRippleEffectEnd = 0x00000301,
        OnShikigamiSkillUpgrade = 0x00000302,
        OnRefreshRoguelikeDungeonCardRsp = 0x00000303,
        OnTakeRoguelikeStageFirstPassReward = 0x00000304,
        OnEnterRoguelikeDungeonNotify = 0x00000305,
        ActivityRogueContentClose = 0x00000306,
        CustomGadgetSubmitRsp = 0x00000307,
        IrodoriEditFlowerSubmitRsp = 0x00000308,
        CustomGadgetPendingDataUnexpectedlyRemoved = 0x00000309,
        ProjectionGameGuideFinishFreeRotationXY = 0x0000030a,
        ProjectionGameGuideFinishFreeRotationZ = 0x0000030b,
        ProjectionGameGuideFinishSwitch = 0x0000030c,
        ProjectionGameAnswerUnlocked = 0x0000030d,
        FireworkMakerRefreshPage = 0x0000030e,
        FireworkReformSettlement = 0x0000030f,
        LanternRiteStartFireworksReformRsp = 0x00000310,
        LanternRiteDoFireworksReformRsp = 0x00000311,
        LanternRiteEndFireworksReformRsp = 0x00000312,
        LanternRiteEndFireworksReform = 0x00000313,
        LanternRiteFireworksReformDoOnce = 0x00000314,
        LocalAvatarStateIDChanged = 0x00000315,
        LocalAvatarAttackTag = 0x00000316,
        LocalAvatarDoSkillSucc = 0x00000317,
        LocalAvatarAnimatorStateChangedBeforeClear = 0x00000318,
        CustomLevelDungeonUpdate = 0x00000319,
        CustomDungeonTryTypeChanged = 0x0000031a,
        CustomLevelSearchResult = 0x0000031b,
        CustomLevelSubscribeResult = 0x0000031c,
        CustomLevelLikeResult = 0x0000031d,
        CustomLevelSaveResult = 0x0000031e,
        RegionalPlayEnable = 0x0000031f,
        RegionalPlayDisable = 0x00000320,
        MichiaeBattleSkillUnlock = 0x00000321,
        ShowSignalMichiae = 0x00000322,
        LifeCountShow = 0x00000323,
        LifeCountHide = 0x00000324,
        LifeCountChange = 0x00000325,
        AttachBartenderEffectNotify = 0x00000326,
        DetachBartenderEffectNotify = 0x00000327,
        BartenderRecipeUnlockNotify = 0x00000328,
        HomeBalloonShootStartNotify = 0x00000329,
        HomeBalloonShootScoreUpdateNotify = 0x0000032a,
        HomeBalloonShootEndNotify = 0x0000032b,
        SpiceActivityProcessFoodRsp = 0x0000032c,
        SpiceActivityFinishMakeSpiceRsp = 0x0000032d,
        IrodoriAcitvityInfoUpdate = 0x0000032e,
        IrodoriAcitvityWatcherInfoUpdate = 0x0000032f,
        FillPoetry = 0x00000330,
        ScanPoetryEntity = 0x00000331,
        MasterGalleryStart = 0x00000332,
        MasterGallerySettle = 0x00000333,
        IrodoriChessEquipCardUpdate = 0x00000334,
        WidgetToyOnPhotographRelease = 0x00000335,
        WidgetToyStartTakingPhoto = 0x00000336,
        OnPhotoSettleNotify = 0x00000337,
        OnGalleryPhotoStart = 0x00000338,
        OnGalleryPhotoEnd = 0x00000339,
        GetQuestLackingResourceRsp = 0x0000033a,
        ArrangeSaveFoundNotify = 0x0000033b,
        ArrangeSaveNotFoundNotify = 0x0000033c,
        UGCLimitedNotify = 0x0000033d,
        UGCLockedNotify = 0x0000033e,
        UGCStateUpdateNotify = 0x0000033f,
        CheckHistorySavesUpdateNotify = 0x00000340,
        MusicGameRewardUnlockNotify = 0x00000341,
        MusicGameRefreshUgcArchivesNotify = 0x00000342,
        MusicGameImportOfficialLevelNotify = 0x00000343,
        MusicGameImportUgcLevelNotify = 0x00000344,
        MusicGameCompareUgcLevelNotify = 0x00000345,
        MusicGameTrialUgcLevelNotify = 0x00000346,
        MusicGamePlayUgcLevelNotify = 0x00000347,
        MusicGameSettleNotify = 0x00000348,
        MusicGameEndNotify = 0x00000349,
        MusicGameRestartNotify = 0x0000034a,
        RogueDiaryCardReroll = 0x0000034b,
        RogueDiaryStartDungeon = 0x0000034c,
        RogueDiaryResetDungeon = 0x0000034d,
        RogueDiaryCardSelected = 0x0000034e,
        RogueDiaryAvatarRevive = 0x0000034f,
        RogueDiaryFinishBanPick = 0x00000350,
        ActivityQuickOpen = 0x00000351,
        ActivitySpecialItem = 0x00000352,
        ChasmChallengeGalleryInfoUpdateNotify = 0x00000353,
        HomeSeekGalleryInfoUpdateNotify = 0x00000354,
    };

    enum class ScenePointType__Enum : int32_t {
        NORMAL = 0x00000000,
        TOWER = 0x00000001,
        PORTAL = 0x00000002,
        Other = 0x00000003,
    };

    struct Vector {
        float _x;
        float _y;
        float _z;
    };

    struct __declspec(align(8)) ConfigScenePoint__Fields {
        ScenePointType__Enum _type;
        struct SimpleSafeUInt32 gadgetIdRawNum;
        struct SimpleSafeUInt16 areaIdRawNum;
        struct Vector3 _pos;
        struct Vector3 _rot;
        struct Vector3 _tranPos;
        struct Vector3 _tranRot;
        bool _unlocked;
        struct String* _alias;
        bool _groupLimit;
        bool _isModelHidden;
    };

    struct ConfigScenePoint {
        void* klass;
        MonitorData* monitor;
        struct ConfigScenePoint__Fields fields;
    };

    struct Nullable_1_UnityEngine_Vector3_ {
        struct Vector3 value;
        bool has_value;
    };

    enum class ElementType__Enum : int32_t {
        None = 0x00000000,
        Fire = 0x00000001,
        Water = 0x00000002,
        Grass = 0x00000003,
        Electric = 0x00000004,
        Ice = 0x00000005,
        Frozen = 0x00000006,
        Wind = 0x00000007,
        Rock = 0x00000008,
        AntiFire = 0x00000009,
        VehicleMuteIce = 0x0000000a,
        COUNT = 0x0000000b,
    };

    enum class Config_WorldAreaType__Enum : int32_t {
        LEVEL_NONE = 0x00000000,
        LEVEL_1 = 0x00000001,
        LEVEL_2 = 0x00000002,
        LEVEL_3 = 0x00000003,
        LEVEL_PLAY = 0x0000000a,
    };

    enum class Config_AreaTerrainType__Enum : int32_t {
        AREA_TERRAIN_NONE = 0x00000000,
        AREA_TERRAIN_CITY = 0x00000001,
        AREA_TERRAIN_OUTDOOR = 0x00000002,
    };

    struct SimpleSafeFloat {
        uint32_t _value;
    };

    struct __declspec(align(8)) MoleMole_Config_WorldAreaConfig__Fields {
        struct SimpleSafeUInt32 IDRawNum;
        struct SimpleSafeUInt32 SceneIDRawNum;
        Config_WorldAreaType__Enum _AreaType;
        struct SimpleSafeUInt32 AreaID_1RawNum;
        struct SimpleSafeUInt32 AreaID_2RawNum;
        bool _AreaDefaultLock;
        uint32_t _AreaNameTextMapHash;
        struct SimpleSafeUInt32 tower_point_idRawNum;
        ElementType__Enum _elementType;
        Config_AreaTerrainType__Enum _terrainType;
        bool _showTips;
        struct SimpleSafeFloat minimapScaleRawNum;
    };

    struct MoleMole_Config_WorldAreaConfig {
        void* klass;
        MonitorData* monitor;
        struct MoleMole_Config_WorldAreaConfig__Fields fields;
    };

    struct BaseEntity__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct BaseEntity* vector[32];
    };

    struct __declspec(align(8)) Dictionary_2_System_UInt32_BaseEntity___Fields {
        struct Int32__Array* buckets;
        struct Dictionary_2_TKey_TValue_Entry_System_UInt32_MoleMole_BaseEntity___Array* entries;
        int32_t count;
        int32_t version;
        int32_t freeList;
        int32_t freeCount;
        struct IEqualityComparer_1_System_UInt32_* comparer;
        struct Dictionary_2_TKey_TValue_KeyCollection_System_UInt32_MoleMole_BaseEntity_* keys;
        struct Dictionary_2_TKey_TValue_ValueCollection_System_UInt32_MoleMole_BaseEntity_* values;
        struct Object* _syncRoot;
    };

    struct Dictionary_2_System_UInt32_BaseEntity_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_UInt32_BaseEntity___Fields fields;
    };

    struct __declspec(align(8)) Dictionary_2_System_String_BaseEntity___Fields {
        struct Int32__Array* buckets;
        struct Dictionary_2_TKey_TValue_Entry_System_String_MoleMole_BaseEntity___Array* entries;
        int32_t count;
        int32_t version;
        int32_t freeList;
        int32_t freeCount;
        struct IEqualityComparer_1_System_String_* comparer;
        struct Dictionary_2_TKey_TValue_KeyCollection_System_String_MoleMole_BaseEntity_* keys;
        struct Dictionary_2_TKey_TValue_ValueCollection_System_String_MoleMole_BaseEntity_* values;
        struct Object* _syncRoot;
    };

    struct Dictionary_2_System_String_BaseEntity_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_String_BaseEntity___Fields fields;
    };

    struct __declspec(align(8)) MapModule__Fields {
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MoleMole_MapModule_MoleMole_MapModule_ScenePointData_* _scenePointDics;
        struct Vector3 _bigworldPos;
        struct String* _activityLimitRegion;
        struct String* _homeworldLimitRegion;
        uint32_t _checkScenePointTimer;
        uint32_t _HENAPPPHGFA_k__BackingField;
        uint32_t _IDKLCPBKKMC_k__BackingField;
        uint32_t _HAIMNNOMKFE_k__BackingField;
        uint32_t _BEGGBAFACOG_k__BackingField;
        uint32_t _LJCHGOJHIBN_k__BackingField;
        uint32_t _CEJAIKKNKEF_k__BackingField;
        bool _isTowerUnlocked_k__BackingField;
        struct List_1_System_UInt32_* dungeonDataLevelConfigIdList;
        struct Nullable_1_UnityEngine_Vector3_ curClientAvatarRebornPoint;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_System_UInt32_* toBeExploredDungeonEntryDic;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_System_UInt32_* canNotBeExploredDungeonEntryDic;
        struct HashSet_1_System_UInt32_* PGNGEOMEDEI;
        struct Dictionary_2_System_UInt32_MoleMole_Config_ConfigScene_* _cfgSceneDic;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MoleMole_Config_ConfigScenePoint_* _cfgPointDic;
        struct List_1_System_UInt32_* _currTransPointList;
        struct List_1_System_UInt32_* _currFunctionalPointList;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MoleMole_MapModule_LJADJIPKKIK_* CJJCAAMGCOM;
        uint32_t _activityPlayId_k__BackingField;
        float MAX_IN_LIMIT_REGION_TIME;
        float _startInLimitRegionTime;
        uint32_t _homeworldRegionSceneId_k__BackingField;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MoleMole_MapModule_MoleMole_MapModule_CityData_* _cityDataDic;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MoleMole_MapModule_MoleMole_MapModule_WorldAreaData_* _worldAreaDataDic;
        struct Dictionary_2_System_UInt32_System_UInt32_* _areaId2ExplorePointDic;
        struct MoleMole_Config_WorldAreaConfig* _currAreaConfig;
        struct MoleMole_BaseEntity* _dungeonQuitPoint;
        struct Dictionary_2_System_UInt32_MoleMole_BaseEntity_* _dungeonWayPointDic;
        struct Dictionary_2_System_UInt32_List_1_System_UInt32_* _dungeonToEntrytDic;
        struct Dictionary_2_System_UInt32_List_1_System_UInt32_* _dungeonToDateDic;
        uint32_t _dungeonCloseTime;
        struct Dictionary_2_System_String_MoleMole_BaseEntity_* _forceFieldDic;
        bool _playerAudioOnEnterDungeonSuccess;
        struct HashSet_1_System_UInt32_* _activatedDungeonWayPoint;
        bool _dungeonEntryOpen;
        struct Dictionary_2_System_UInt32_System_Boolean_* _sceneUnlockDic;
        struct Dictionary_2_System_UInt32_List_1_System_UInt32_* _sceneTagList;
        struct List_1_MoleMole_MapModule_MoleMole_MapModule_ScannerInfo_* _scannerInfoList;
        struct List_1_MoleMole_MapAreaMistData_* _mistDataList;
        struct List_1_MoleMole_MapAreaMistData_* _openMistDataList;
        struct List_1_MoleMole_MapAreaMistData_* _newOpenMistDataList;
        struct List_1_System_UInt32_* dirtyMistDataList;
        struct Transform* _mapAreaFog;
        struct Dictionary_2_System_String_MoleMole_MapModule_MoleMole_MapModule_PrefabHandle_* _prefabHandleDict;
    };

    struct MoleMole_MapModule {
        struct MapModule__Class* klass;
        MonitorData* monitor;
        struct MapModule__Fields fields;
    };

    struct MapModule_ScenePointData {
        bool isUnlocked;
        struct ConfigScenePoint* config;
        bool isGroupLimit;
        bool isModelHidden;
        uint32_t entityId;
        uint32_t level;
    };

    enum class MoleMole_Config_MapTagType__Enum : int32_t {
        BigWorld = 0x00000000,
        HomeWorld = 0x00000001,
        Islands = 0x00000002,
        Abyssalisle = 0x00000003,
        MichiaeMatsuri = 0x00000004,
        TheChasm = 0x00000005,
    };

    enum class MoleMole_CustomMarkTrackReasonType__Enum : int32_t {
        Noe = 0x00000000,
        Monster = 0x00000001,
        Quest = 0x00000002,
    };

    struct Rect {
        float m_XMin;
        float m_YMin;
        float m_Width;
        float m_Height;
    };

    enum class MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_MarkTipsContentType__Enum : int32_t {
        Normal = 0x00000000,
        AddCustomMark = 0x00000001,
        EditCustomMark = 0x00000002,
        Dungeon = 0x00000003,
        Boss = 0x00000004,
        Routine = 0x00000005,
        MapTagSwitch = 0x00000006,
        TemplateMapTips = 0x00000007,
    };

    enum class MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryState__Enum : int32_t {
        LOCKED = 0x00000000,
        TOBEEXPLORE = 0x00000001,
        UNLOCKED = 0x00000002,
    };

    enum class MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonTabSelectState__Enum : int32_t {
        NotReady = 0x00000000,
        SelectTitle = 0x00000001,
        SelectReward = 0x00000002,
        DailyReward = 0x00000003,
    };

    struct MoleMole_WeeklyBossResinDiscountInfoStruct {
        uint32_t discountNum;
        uint32_t discountNumLimit;
        uint32_t resinCost;
        uint32_t originalResinCost;
    };

    struct MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryInfo {
        uint32_t id;
        bool isPassed;
        uint32_t maxBossChestNum;
        uint32_t openedBossCheestNum;
        uint32_t nextRefreshTime;
        struct MoleMole_WeeklyBossResinDiscountInfoStruct weeklyBossResinDiscount;
    };

    struct MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryInfoList {
        int32_t count;
        struct MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryInfo first;
        struct MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryInfo second;
        struct MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryInfo third;
        struct MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryInfo fourth;
    };

    struct MoleMole_ItemTipsDialogHelper {
        struct MoleMole_ItemTipsDialogContext* _dialog;
    };

    enum class CursorLockMode__Enum : int32_t {
        None = 0x00000000,
        Locked = 0x00000001,
        Confined = 0x00000002,
    };

    struct Dictionary_2_System_UInt32_MapModule_ScenePointData___Array {
        struct Dictionary_2_System_UInt32_MoleMole_MapModule_ScenePointData___Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct Dictionary_2_System_UInt32_MoleMole_MapModule_ScenePointData_* vector[32];
    };

    struct MapModule_ScenePointData__Array {
        struct MoleMole_MapModule_MoleMole_MapModule_ScenePointData__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct MapModule_ScenePointData vector[32];
    };

    struct __declspec(align(8)) Dictionary_2_System_UInt32_MapModule_ScenePointData___Fields {
        struct Int32__Array* table;
        struct Link__Array* linkSlots;
        struct UInt32__Array* keySlots;
        struct MapModule_ScenePointData__Array* valueSlots;
        int32_t touchedSlots;
        int32_t emptySlot;
        int32_t count;
        int32_t threshold;
        void* hcp;
        void* serialization_info;
        int32_t generation;
    };

    struct __declspec(align(8)) Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MapModule_ScenePointData___Fields {
        struct Int32__Array* table;
        struct Link__Array* linkSlots;
        struct UInt32__Array* keySlots;
        struct Dictionary_2_System_UInt32_MapModule_ScenePointData___Array* valueSlots;
        int32_t touchedSlots;
        int32_t emptySlot;
        int32_t count;
        int32_t threshold;
        void* hcp;
        void* serialization_info;
        int32_t generation;
    };

    struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MapModule_ScenePointData_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_MapModule_ScenePointData___Fields fields;
    };

    struct Dictionary_2_System_UInt32_MoleMole_MapModule_ScenePointData_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_System_UInt32_MapModule_ScenePointData___Fields fields;
    };

    struct Notify {
        MoleMole_NotifyTypes__Enum type;
        struct Object* body;
        struct Packet* udpPacket;
    };

    struct __declspec(align(8)) Dictionary_2_SafeUInt32_JKNLDEEBGLL___Fields {
        struct Int32__Array* table;
        struct Link__Array* linkSlots;
        struct SafeUInt32__Array* keySlots;
        struct JKNLDEEBGLL__Array* valueSlots;
        int32_t touchedSlots;
        int32_t emptySlot;
        int32_t count;
        int32_t threshold;
        struct IEqualityComparer_1_SafeUInt32_* hcp;
        struct SerializationInfo* serialization_info;
        int32_t generation;
    };

    struct SafeUInt32 {
        int64_t _data1;
        int64_t _data2;
    };

    struct SafeUInt32__Array {
        struct SafeUInt32__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct SafeUInt32 vector[32];
    };

    struct Dictionary_2_SafeUInt32_JKNLDEEBGLL_ {
        void* klass;
        MonitorData* monitor;
        struct Dictionary_2_SafeUInt32_JKNLDEEBGLL___Fields fields;
    };

    struct JKNLDEEBGLL {
        int64_t OBMDKAHDODE;
        int64_t EEADNINIHGI;
    };

    struct JKNLDEEBGLL__Boxed {
        struct JKNLDEEBGLL__Class* klass;
        MonitorData* monitor;
        struct JKNLDEEBGLL fields;
    };

    struct JKNLDEEBGLL__Array {
        struct JKNLDEEBGLL__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct JKNLDEEBGLL vector[32];
    };

    enum class PropType__Enum : uint32_t {
        PROP_NONE = 0x00000000,
        PROP_EXP = 0x000003e9,
        PROP_BREAK_LEVEL = 0x000003ea,
        PROP_SATIATION_VAL = 0x000003eb,
        PROP_SATIATION_PENALTY_TIME = 0x000003ec,
        PROP_GEAR_START_VAL = 0x000007d1,
        PROP_GEAR_STOP_VAL = 0x000007d2,
        PROP_LEVEL = 0x00000fa1,
        PROP_LAST_CHANGE_AVATAR_TIME = 0x00002711,
        PROP_MAX_SPRING_VOLUME = 0x00002712,
        PROP_CUR_SPRING_VOLUME = 0x00002713,
        PROP_IS_SPRING_AUTO_USE = 0x00002714,
        PROP_SPRING_AUTO_USE_PERCENT = 0x00002715,
        PROP_IS_FLYABLE = 0x00002716,
        PROP_IS_WEATHER_LOCKED = 0x00002717,
        PROP_IS_GAME_TIME_LOCKED = 0x00002718,
        PROP_IS_TRANSFERABLE = 0x00002719,
        PROP_MAX_STAMINA = 0x0000271a,
        PROP_CUR_PERSIST_STAMINA = 0x0000271b,
        PROP_CUR_TEMPORARY_STAMINA = 0x0000271c,
        PROP_PLAYER_LEVEL = 0x0000271d,
        PROP_PLAYER_EXP = 0x0000271e,
        PROP_PLAYER_HCOIN = 0x0000271f,
        PROP_PLAYER_SCOIN = 0x00002720,
        PROP_PLAYER_MP_SETTING_TYPE = 0x00002721,
        PROP_IS_MP_MODE_AVAILABLE = 0x00002722,
        PROP_PLAYER_WORLD_LEVEL = 0x00002723,
        PROP_PLAYER_RESIN = 0x00002724,
        PROP_PLAYER_WAIT_SUB_HCOIN = 0x00002726,
        PROP_PLAYER_WAIT_SUB_SCOIN = 0x00002727,
        PROP_IS_ONLY_MP_WITH_PS_PLAYER = 0x00002728,
        PROP_PLAYER_MCOIN = 0x00002729,
        PROP_PLAYER_WAIT_SUB_MCOIN = 0x0000272a,
        PROP_PLAYER_LEGENDARY_KEY = 0x0000272b,
        PROP_IS_HAS_FIRST_SHARE = 0x0000272c,
        PROP_PLAYER_FORGE_POINT = 0x0000272d,
        PROP_CUR_CLIMATE_METER = 0x00002733,
        PROP_CUR_CLIMATE_TYPE = 0x00002734,
        PROP_CUR_CLIMATE_AREA_ID = 0x00002735,
        PROP_CUR_CLIMATE_AREA_CLIMATE_TYPE = 0x00002736,
        PROP_PLAYER_WORLD_LEVEL_LIMIT = 0x00002737,
        PROP_PLAYER_WORLD_LEVEL_ADJUST_CD = 0x00002738,
        PROP_PLAYER_LEGENDARY_DAILY_TASK_NUM = 0x00002739,
        PROP_PLAYER_HOME_COIN = 0x0000273a,
        PROP_PLAYER_WAIT_SUB_HOME_COIN = 0x0000273b,
        PROP_IS_AUTO_UNLOCK_SPECIFIC_EQUIP = 0x0000273c,
    };

    struct __declspec(align(8)) BaseComponentPlugin__Fields {
        struct BaseComponent* owner;
        bool isInited;
        bool hasTick;
        bool hasLateTick;
        struct Int32__Array* _selfOnEventIDsCache;
        bool _isSelfOnEventIDsCached;
        struct Int32__Array* _selfOnEventResolvedIDsCache;
        bool _isSelfOnEventResolvedIDsCached;
        struct Int32__Array* _selfListenEventIDsCache;
        bool _isSelfListenEventIDsCached;
        bool _enabled;
        bool _hasEnabledInited;
        bool _listenEventValid_k__BackingField;
    };

    struct BaseComponentPlugin {
        Il2CppClass* klass;
        MonitorData* monitor;
        struct BaseComponentPlugin__Fields fields;
    };

    struct LevelSyncCombatPlugin__Fields {
        struct BaseComponentPlugin__Fields _;
        struct List_1_MoleMole_CombatEntryProxy_* IKPLMBFILHG;
        float _flushTimeAcc;
    };

    struct LevelSyncCombatPlugin {
        struct LevelSyncCombatPlugin__Class* klass;
        MonitorData* monitor;
        struct LevelSyncCombatPlugin__Fields fields;
    };

    struct __declspec(align(8)) List_1_MoleMole_CombatEntryProxy___Fields {
        struct MoleMole_CombatEntryProxy__Array* _items;
        int32_t _size;
        int32_t _version;
        struct Object* _syncRoot;
    };

    struct List_1_MoleMole_CombatEntryProxy_ {
        struct List_1_MoleMole_CombatEntryProxy___Class* klass;
        MonitorData* monitor;
        struct List_1_MoleMole_CombatEntryProxy___Fields fields;
    };

    struct MoleMole_CombatEntryProxy__Array {
        struct MoleMole_CombatEntryProxy__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct MoleMole_CombatEntryProxy* vector[32];
    };

    enum class GBCFKNINCEI__Enum : int32_t {
        HAKNGINBAOC = 0x00000000,
        NGEKCHOHNOP = 0x00000001,
        ILNKLKMFPEK = 0x00000002,
        FBMKDOBDCAH = 0x00000003,
        DIFAKMKJBLO = 0x00000004,
        ICHJIGAMFOE = 0x00000005,
        BADAJKFEECO = 0x00000006,
        PDNFEHPDLFJ = 0x00000007,
        IONAKFGOPKC = 0x00000008,
        LLMMGINHILB = 0x00000009,
        PONJALOOAAJ = 0x0000000a,
        BLBGDJOBDCA = 0x0000000b,
        NNHMAMFCPKO = 0x0000000c,
        LKFOOCDOEBK = 0x0000000d,
        HNPDJAIAKIM = 0x0000000e,
        CNEKEMFNBLD = 0x0000000f,
        LJEAKMDCMFF = 0x00000010,
    };

    // PEHBOMIKLHF__Enum
    enum class ForwardType__Enum : int32_t {
        ForwardLocal = 0x00000000,
        ForwardToAll = 0x00000001,
        ForwardToAllExceptCur = 0x00000002,
        ForwardToHost = 0x00000003,
        ForwardToAllGuest = 0x00000004,
        ForwardToPeer = 0x00000005,
        ForwardToPeers = 0x00000006,
        ForwardOnlyServer = 0x00000007,
        ForwardToAllExistExceptCur = 0x00000008,
    };

    struct __declspec(align(8)) NHHMPCAAKGF__Fields {
        bool GNKMNOEMHEH;
        struct Byte__Array* BEEHBAABKNH;
    };

    struct NHHMPCAAKGF {
        void* klass;
        MonitorData* monitor;
        struct NHHMPCAAKGF__Fields fields;
    };

    struct HPAJEKCBMID__Fields {
        struct MessageBase_1__Fields _;
        GBCFKNINCEI__Enum FNCGEGNMAAD;
        ForwardType__Enum PPBIOJBJAHO;
        struct NHHMPCAAKGF* GEOJBAGNEDC;
    };

    struct HPAJEKCBMID {
        struct HPAJEKCBMID__Class* klass;
        MonitorData* monitor;
        struct HPAJEKCBMID__Fields fields;
    };

    struct __declspec(align(8)) AJKACNNKJGG__Fields {
        struct HPAJEKCBMID* PANOALIPEFB;
        struct MAKEGCIBGMD* IHFPAPEDDBM;
    };

    struct AJKACNNKJGG {
        void* klass;
        MonitorData* monitor;
        struct AJKACNNKJGG__Fields fields;
    };

    // CMAGCELPFOP
    enum class EventID__Enum : int32_t {
        None = 0x00000000,
        EvtAbilityAudio = 0x00000001,
        EvtAbilityStart = 0x00000002,
        EvtApplyModifier = 0x00000003,
        EvtAttachment = 0x00000004,
        EvtAttackLanded = 0x00000005,
        EvtAudio = 0x00000006,
        EvtAvatarBecomeThreat = 0x00000007,
        EvtAvatarAppear = 0x00000008,
        EvtAvatarChanged = 0x00000009,
        EvtAvatarDieEnd = 0x0000000a,
        EvtAvatarEnterFocus = 0x0000000b,
        EvtAvatarEquipChanged = 0x0000000c,
        EvtAvatarExitFocus = 0x0000000d,
        EvtAvatarInBattle = 0x0000000e,
        EvtBeingHealed = 0x0000000f,
        EvtBeingHit = 0x00000010,
        EvtBeingHitEnd = 0x00000011,
        EvtBeingHitResult = 0x00000012,
        EvtBillboard = 0x00000013,
        EvtBuffAdd = 0x00000014,
        EvtBuffRemove = 0x00000015,
        EvtCameraFrameTransition = 0x00000016,
        EvtCameraMove = 0x00000017,
        EvtCameraMoveClear = 0x00000018,
        EvtCameraSceneLook = 0x00000019,
        EvtCameraFieldLook = 0x0000001a,
        EvtPlayerDie = 0x0000001b,
        EvtChangeAvatar = 0x0000001c,
        EvtChangeProp = 0x0000001d,
        EvtCombatEnd = 0x0000001e,
        EvtCrash = 0x0000001f,
        EvtCreateGadgetToEquipPart = 0x00000020,
        EvtCure = 0x00000021,
        EvtBleeding = 0x00000022,
        EvtCutsceneNotify = 0x00000023,
        EvtDoSkillSucc = 0x00000024,
        EvtForceUseSkillSucc = 0x00000025,
        EvtEntityEffectChange = 0x00000026,
        EvtElementReaction = 0x00000027,
        EvtEntityEnterSurface = 0x00000028,
        EvtEntityExitSurface = 0x00000029,
        EvtEntityResetSurface = 0x0000002a,
        EvtEquipAttached = 0x0000002b,
        EvtEquipDestroy = 0x0000002c,
        EvtEquipDetached = 0x0000002d,
        EvtFallOnGround = 0x0000002e,
        EvtFieldEnter = 0x0000002f,
        EvtFieldExit = 0x00000030,
        EvtFightPropChangeReason = 0x00000031,
        EvtFlag = 0x00000032,
        EvtForceQuitStoryCamera = 0x00000033,
        EvtGadgetState = 0x00000034,
        EvtGadgetEnableInteract = 0x00000035,
        EvtHeadControl = 0x00000036,
        EvtHeal = 0x00000037,
        EvtHittingOther = 0x00000038,
        EvtHittingScene = 0x00000039,
        EvtHPChange = 0x0000003a,
        EvtInteraction = 0x0000003b,
        EvtInterFree = 0x0000003c,
        EvtInterruptIntee = 0x0000003d,
        EvtKill = 0x0000003e,
        EvtMonsterTryDropEquip = 0x0000003f,
        EvtOpenChest = 0x00000040,
        EvtPickupGadget = 0x00000041,
        EvtPickupGadgetCallBack = 0x00000042,
        EvtRemoveModifier = 0x00000043,
        EvtRevive = 0x00000044,
        EvtRutimeIDRetarget = 0x00000045,
        EvtDoTileAction = 0x00000046,
        EvtSceneAudioPostMIDIEvent = 0x00000047,
        EvtSetCameraLockTime = 0x00000048,
        EvtShoppingFinish = 0x00000049,
        EvtSkillStart = 0x0000004a,
        EvtShareCDSkillStart = 0x0000004b,
        EvtCameraLock = 0x0000004c,
        EvtTeamChanged = 0x0000004d,
        EvtReserveTeamChanged = 0x0000004e,
        EvtThrowGadget = 0x0000004f,
        EvtTransmitAvatar = 0x00000050,
        EvtTurnDirection = 0x00000051,
        EvtUIBackBlur = 0x00000052,
        EvtWorktopOption = 0x00000053,
        EvtLoopStart = 0x00000054,
        EvtInterFinish = 0x00000055,
        EvtInterDialogFinish = 0x00000056,
        EvtAttachAnimatorParam = 0x00000057,
        EvtEntityDestroy = 0x00000058,
        EvtEntityTimeScaleChange = 0x00000059,
        EvtEntityGhostChange = 0x0000005a,
        EvtEntityActiveChange = 0x0000005b,
        EvtEntityAliveChange = 0x0000005c,
        EvtPlayStageChange = 0x0000005d,
        EvtPlayUidChange = 0x0000005e,
        EvtGlobalValueChange = 0x0000005f,
        EvtGlobalValueCreated = 0x00000060,
        EvtGlobalValueClear = 0x00000061,
        EvtServerGlobalValueChange = 0x00000062,
        EvtAppearFromServer = 0x00000063,
        EvtAbilityRefreshed = 0x00000064,
        EvtAISoundBroadcast = 0x00000065,
        EvtAISoundAttraction = 0x00000066,
        EvtAIDeadth = 0x00000067,
        EvtBoundInCity = 0x00000068,
        EvtEntityActive = 0x00000069,
        EvtEntityCreated = 0x0000006a,
        EvtEntityReady = 0x0000006b,
        EvtEntityRemoved = 0x0000006c,
        EvtEntityResetPos = 0x0000006d,
        EvtEntityReconnect = 0x0000006e,
        EvtEntitySynced = 0x0000006f,
        EvtInputChange = 0x00000070,
        EvtMsgBoard = 0x00000071,
        EvtMultiplayer = 0x00000072,
        EvtPlatformChangeRoute = 0x00000073,
        EvtPlatformStartRoute = 0x00000074,
        EvtPlatformStopRoute = 0x00000075,
        EvtRoomVisiable = 0x00000076,
        EvtSceneCollider = 0x00000077,
        EvtSceneRouteChange = 0x00000078,
        EvtShowReminder = 0x00000079,
        EvtInterruptReminder = 0x0000007a,
        EvtTemplateReminder = 0x0000007b,
        EvtStageCreated = 0x0000007c,
        EvtStageDestroying = 0x0000007d,
        EvtStageProgress = 0x0000007e,
        EvtStageReady = 0x0000007f,
        EvtWillCreateStage = 0x00000080,
        EvtQuestState = 0x00000081,
        EvtWeatherChange = 0x00000082,
        EvtThunder = 0x00000083,
        EvtSkyThunder = 0x00000084,
        EvtWindSeedNotify = 0x00000085,
        EvtWindSeedMixinInfo = 0x00000086,
        EvtTransportAvatar = 0x00000087,
        EvtMonsterAppear = 0x00000088,
        EvtShieldAdded = 0x00000089,
        EvtWatcherSysAction = 0x0000008a,
        EvtAreaLevelChange = 0x0000008b,
        EvtAnimatorStateChanged = 0x0000008c,
        EvtAnimatorTransitionFinish = 0x0000008d,
        EvtStateIDChanged = 0x0000008e,
        EvtEntityReadyPost = 0x0000008f,
        EvtGainCrystalSeed = 0x00000090,
        EvtMovingWaterStop = 0x00000091,
        EvtMovingWaterChangeState = 0x00000092,
        EvtAnimatorStateChangedBeforeClear = 0x00000093,
        EvtSkillDepotIdChanged = 0x00000094,
        EvtEntityAnimeLoadFinishPost = 0x00000095,
        EvtEntityAnimeReadyPost = 0x00000096,
        EvtAvatarDownRayTrigger = 0x00000097,
        EvtGadgetChainLevelChange = 0x00000098,
        EvtGadgetChainInteracted = 0x00000099,
        EvtVehicleInteract = 0x0000009a,
        EvtZoneInteract = 0x0000009b,
        EvtChangeFly = 0x0000009c,
        EvtElectricCoreMoveEnterP1 = 0x0000009d,
        EvtElectricCoreMoveInterrupt = 0x0000009e,
        EvtAvatarEnterViewBias = 0x0000009f,
        EvtAvatarExitViewBias = 0x000000a0,
        EvtWidgetActiveStateChange = 0x000000a1,
        EvtMultiplayersCountChanged = 0x000000a2,
        EvtWidgetExCDChange = 0x000000a3,
        EvtPlayerLevelUpdate = 0x000000a4,
        EvtNormalSceneTransPointUnlock = 0x000000a5,
        EvtFireworkStartCountDown = 0x000000a6,
        EvtTriggerUGCGadgetMove = 0x000000a7,
        EvtSkillReady = 0x000000a8,
        EvtCount = 0x000000a9,
    };

    enum class EventRemoteState__Enum {
        Local = 0x00000000,
        IsForwarded = 0x00000001,
    };

    // BaseEvent
    struct __declspec(align(8)) BaseEvent__Fields {
        EventID__Enum eventID;
        uint32_t targetID;
        bool canBeHandledImmediately;
        bool canBeHandledByLogic;
        bool canBeHandledByVisual;
        bool canBeHandledByLogicResolved;
        bool canBeHandledByDispatcher;
        bool canBeHandledOnlyByListeners;
        bool canBeHandledIfDie;
        bool fromEventCache;
        EventRemoteState__Enum remoteState;
        ForwardType__Enum forwardType;
        uint32_t fromPeerID;
    };

    struct AttackLanded__Fields {
        struct BaseEvent__Fields _;
        uint32_t _attackerID;
        uint32_t _attackeeID;
        struct AttackResult* _attackResult;
    };

    struct AttackLanded {
        void* klass;
        MonitorData* monitor;
        struct AttackLanded__Fields fields;
    };

    enum class ElementReactionType__Enum : int32_t {
        None = 0x00000000,
        Explode = 0x00000001,
        Stream = 0x00000002,
        Burning = 0x00000003,
        Burned = 0x00000004,
        Wet = 0x00000005,
        Overgrow = 0x00000006,
        Melt = 0x00000007,
        Freeze = 0x00000008,
        AntiFire = 0x00000009,
        Rock = 0x0000000a,
        SlowDown = 0x0000000b,
        Shock = 0x0000000c,
        Wind = 0x0000000d,
        Electric = 0x0000000e,
        Fire = 0x0000000f,
        Superconductor = 0x00000010,
        SwirlFire = 0x00000011,
        SwirlWater = 0x00000012,
        SwirlElectric = 0x00000013,
        SwirlIce = 0x00000014,
        SwirlFireAccu = 0x00000015,
        SwirlWaterAccu = 0x00000016,
        SwirlElectricAccu = 0x00000017,
        SwirlIceAccu = 0x00000018,
        StickRock = 0x00000019,
        StickWater = 0x0000001a,
        CrystallizeFire = 0x0000001b,
        CrystallizeWater = 0x0000001c,
        CrystallizeElectric = 0x0000001d,
        CrystallizeIce = 0x0000001e,
        FrozenBroken = 0x0000001f,
        StickGrass = 0x00000020,
        Overdose = 0x00000021,
    };

    enum class AttackResult_EndureBreakLevel__Enum : uint32_t {
        None = 0x00000000,
        OnlyShake = 0x00000001,
        Break = 0x00000002,
    };

    enum class AttackResult_AttackSpecific__Enum : int32_t {
        None = 0x00000000,
        Attack = 0x00000001,
        MassiveAttack = 0x00000002,
        Proto = 0x00000003,
        AttackeeInvalid = 0x00000004,
    };

    struct AttackResult_HitCollsion {
        uint32_t hitIndex;
        struct Collider* hitCollider;
        struct Vector3 hitDir;
        struct Vector3 hitPoint;
        float attackeeHitForceAngle;
        float attackeeHitEntityAngle;
    };

    enum class TargetType__Enum : int32_t {
        None = 0x00000000,
        Alliance = 0x00000001,
        Enemy = 0x00000002,
        Self = 0x00000003,
        SelfCamp = 0x00000004,
        All = 0x00000005,
        AllExceptSelf = 0x00000006,
    };

    struct Nullable_1_MoleMole_Config_TargetType_ {
        TargetType__Enum value;
        bool has_value;
    };

    enum class HitBoxType__Enum : int32_t {
        Normal = 0x00000000,
        Head = 0x00000001,
    };


    struct AbilityIdentifier {
        void* instancedAbility;
        void* instancedModifier;
        int32_t localId;
        uint32_t instancedAbilityID;
        uint32_t abilityCasterID;
        bool abilityIsValid;
        uint32_t instancedModifierID;
        uint32_t modifierOwnerID;
        bool isModifierValid;
    };

    struct Nullable_1_MoleMole_AbilityIdentifier_ {
        struct AbilityIdentifier value;
        bool has_value;
    };

    enum class StrikeType__Enum : int32_t {
        Default = 0x00000000,
        Slash = 0x00000001,
        Blunt = 0x00000002,
        Pierce = 0x00000003,
        Spear = 0x00000004,
        None = 0x00000005,
    };

    enum class AttackType__Enum : int32_t {
        None = 0x00000000,
        Melee = 0x00000001,
        Range = 0x00000002,
        Default = 0x00000003,
    };

    struct __declspec(align(8)) ConfigAttackProperty__Fields {
        void* _damagePercentage;
        void* _damagePercentageRatio;
        ElementType__Enum _elementType;
        struct SimpleSafeFloat elementRankRawNum;
        void* _elementDurability;
        bool _overrideByWeapon;
        bool _ignoreAttackerProperty;
        StrikeType__Enum _strikeType;
        struct SimpleSafeFloat enBreakRawNum;
        struct SimpleSafeFloat enHeadBreakRawNum;
        AttackType__Enum _attackType;
        void* _damageExtra;
        void* _bonusCritical;
        void* _bonusCriticalHurt;
        bool _ignoreLevelDiff;
        bool _trueDamage;
        bool MNLLIPMAHJM;
    };

    struct ConfigAttackProperty {
        void* klass;
        MonitorData* monitor;
        struct ConfigAttackProperty__Fields fields;
    };

    enum class HitLevel__Enum : int32_t {
        Mute = 0x00000000,
        Shake = 0x00000001,
        Light = 0x00000002,
        Heavy = 0x00000003,
        Air = 0x00000004,
    };

    enum class RetreatType__Enum : int32_t {
        ByAttacker = 0x00000000,
        ByHitDirection = 0x00000001,
        ByTangent = 0x00000002,
        ByOriginOwner = 0x00000003,
        ByHitDirectionInverse = 0x00000004,
        ByAttackerForward = 0x00000005,
    };

    struct __declspec(align(8)) ConfigHitPattern__Fields {
        struct String* _onHitEffectName;
        HitLevel__Enum _hitLevel;
        struct EJABEMMALJF* _hitImpulseX;
        struct EJABEMMALJF* _hitImpulseY;
        struct String* _hitImpulseType;
        struct NLDKMJMPBKE* _overrideHitImpulse;
        RetreatType__Enum _retreatType;
        struct SimpleSafeFloat hitHaltTimeRawNum;
        struct SimpleSafeFloat hitHaltTimeScaleRawNum;
        bool _canBeDefenceHalt;
        bool _muteHitText;
        bool _recurring;
        bool LKMCCNGPNBA;
    };

    struct AttackResult_AttackHitEffectResult {
        HitLevel__Enum hitEffLevel;
        HitLevel__Enum originHitEffLevel;
        float retreatStrength;
        float airStrength;
        float hitHaltTime;
        float hitHaltTimeScale;
    };

    struct ConfigHitPattern {
        void* klass;
        MonitorData* monitor;
        struct ConfigHitPattern__Fields fields;
    };

    struct SafeUInt64 {
        int64_t _data1;
        int64_t _data2;
    };

    struct SafeInt32 {
        int64_t _data1;
        int64_t _data2;
    };

    struct SafeInt64 {
        int64_t _data1;
        int64_t _data2;
    };

    struct SafeFloat {
        int64_t _data1;
        int64_t _data2;
    };

    struct SafeDouble {
        int64_t _data1;
        int64_t _data2;
    };

    struct SafeFloat__Boxed {
        struct SafeFloat__Class* klass;
        MonitorData* monitor;
        struct SafeFloat fields;
    };

    struct FixedBoolStack {
        struct FixedBoolStack__Class* klass;
        MonitorData* monitor;
        // struct FixedBoolStack__Fields fields;
    };

    struct __declspec(align(8)) CombatProperty__Fields {
        struct SafeFloat maxHP;
        struct SafeFloat HP;
        struct SafeFloat elemEnergy;
        struct SafeFloat maxElemEnergy;
        struct SafeFloat attackBase;
        struct SafeFloat attackPermanent;
        struct SafeFloat defenseBase;
        struct SafeFloat defensePermanent;
        struct SafeFloat addHurtBase;
        struct SafeFloat subHurtBase;
        struct SafeFloat criticalHurtBase;
        struct SafeFloat criticalBase;
        struct SafeFloat antiCriticalBase;
        struct SafeFloat physicalSubHurtBase;
        struct SafeFloat fireSubHurtBase;
        struct SafeFloat grassSubHurtBase;
        struct SafeFloat waterSubHurtBase;
        struct SafeFloat elecSubHurtBase;
        struct SafeFloat windSubHurtBase;
        struct SafeFloat iceSubHurtBase;
        struct SafeFloat rockSubHurtBase;
        struct SafeFloat physicalMuteHurtBase;
        struct SafeFloat fireMuteHurtBase;
        struct SafeFloat grassMuteHurtBase;
        struct SafeFloat waterMuteHurtBase;
        struct SafeFloat elecMuteHurtBase;
        struct SafeFloat windMuteHurtBase;
        struct SafeFloat iceMuteHurtBase;
        struct SafeFloat rockMuetHurtBase;
        struct SafeFloat physicalAddHurtBase;
        struct SafeFloat fireAddHurtBase;
        struct SafeFloat grassAddHurtBase;
        struct SafeFloat waterAddHurtBase;
        struct SafeFloat elecAddHurtBase;
        struct SafeFloat windAddHurtBase;
        struct SafeFloat iceAddHurtBase;
        struct SafeFloat rockAddHurtBase;
        struct SafeFloat hitHeadDmgRatioBase;
        struct SafeFloat defenseIgnoreRatioBase;
        struct SafeFloat defenseIgnoreDeltaBase;
        struct SafeFloat elementMasteryBase;
        struct SafeFloat elemReactSwirlFireDeltaBase;
        struct SafeFloat elemReactSwirlIceDeltaBase;
        struct SafeFloat elemReactSwirlWaterDeltaBase;
        struct SafeFloat elemReactSwirlElectricDeltaBase;
        struct SafeFloat elemReactSConductDeltaBase;
        struct SafeFloat elemReactSteamDeltaBase;
        struct SafeFloat elemReactMeltDeltaBase;
        struct SafeFloat elemReactElectricDeltaBase;
        struct SafeFloat elemReactBurnDeltaBase;
        struct SafeFloat elemReactFreezeDeltaBase;
        struct SafeFloat elemReactExplodeDeltaBase;
        struct SafeFloat effectHit;
        struct SafeFloat effectResist;
        struct SafeFloat freezeResist;
        struct SafeFloat torporResist;
        struct SafeFloat dizzyResist;
        struct SafeFloat freezeShorten;
        struct SafeFloat torporShorten;
        struct SafeFloat dizzyShorten;
        struct SafeFloat healAddBase;
        struct SafeFloat healedAddBase;
        struct SafeFloat chargeEfficiencyBase;
        struct SafeFloat skillCDMinusRatioBase;
        struct SafeFloat shieldCostMinusRatioBase;
        struct SafeFloat level;
        struct SafeFloat exp;
        ElementType__Enum elemType;
        struct SafeFloat weight;
        struct SafeFloat endure;
        struct SafeFloat endureShake;
        struct SafeFloat gaugeLength;
        struct SafeFloat waneSpeed;
        struct SafeFloat recoverTime;
        struct SafeFloat endurance;
        struct FixedBoolStack* denyLockOn;
        struct FixedBoolStack* isInvincible;
        struct FixedBoolStack* islockHP;
        struct FixedBoolStack* isNoheal;
        struct FixedBoolStack* isGhostToAllied;
        struct FixedBoolStack* isGhostToEnemy;
        struct FixedBoolStack* canTriggerBullet;
        struct FixedBoolStack* denyElementStick;
        struct LCAbilityState* _ability;
        bool useAbilityProperty;
    };

    struct CombatProperty {
        struct OIAODCALEJK__Class* klass;
        MonitorData* monitor;
        struct CombatProperty__Fields fields;
    };

    struct __declspec(align(8)) AttackResult__Fields {
        struct CombatProperty* attackerCombatProperty;
        struct CombatProperty* defenseCombatProperty;
        bool attackeeDummyEntity;
        float damage;
        float damageShield;
        bool critical;
        uint32_t criticalRand;
        bool isResistText;
        bool muteElementHurt;
        struct String* onHitEffectName;
        uint32_t attackTimeStamp;
        struct Nullable_1_MoleMole_Config_TargetType_  targetType;
        AttackResult_AttackSpecific__Enum attackType;
        struct AttackResult_HitCollsion  hitCollision;
        HitBoxType__Enum hitPosType;
        struct String* animEventId;
        struct String* attackTag;
        struct String* attenuationTag;
        struct String* attenuationGroup;
        uint32_t attenuationCount;
        float elementdurabilityAttenuation;
        struct Nullable_1_MoleMole_AbilityIdentifier_ abilityIdentifier;
        bool useGadgetDamageAction;
        uint32_t gadgetDamageActionIdx;
        bool canHitHead;
        float elementReductionRate;
        float elementAmplifyRate;
        ElementReactionType__Enum elementAmplifyType;
        ElementReactionType__Enum elementAddhurtType;
        ElementReactionType__Enum elementReactionType;
        struct ConfigAttackProperty* _attackerAttackProperty;
        void* modifiedAttackProperty;
        float AMJDLLOENNI;
        ElementType__Enum _origElementType;
        float _origElementDurability;
        float endureDelta;
        AttackResult_EndureBreakLevel__Enum endureBreak;
        struct Vector3 resolvedDir;
        struct ConfigHitPattern* attackerHitPattern;
        struct AttackResult_AttackHitEffectResult hitEffResult;
        bool attackerForceCameraShake;
        struct ConfigCameraShake* attackerCameraShake;
        float bulletFlyTime;
        struct ConfigBulletWane* bulletWane;
        int32_t rejectState;
        struct SafeUInt32 AADHIMJJCHK;
        struct SafeUInt32 CMNNNKEGKFI;
        struct SafeUInt32 KBDMDNEKOLK;
        struct SafeUInt32 HLIIHHNHHNP;
        struct SafeUInt32 EMBFNJJJPNG;
        struct Vector3 hitRetreatDir;
    };

    struct AttackResult {
        void* klass;
        MonitorData* monitor;
        struct AttackResult__Fields fields;
    };

    struct AbilityIdentifier_1__Fields {
        struct MessageBase_1__Fields _;
        uint32_t instancedAbilityId_;
        uint32_t abilityCasterId_;
        int32_t localId_;
        uint32_t instancedModifierId_;
        uint32_t modifierOwnerId_;
        bool isServerbuffModifier_;
    };

    struct AbilityIdentifier_1 {
        void* klass;
        MonitorData* monitor;
        struct AbilityIdentifier_1__Fields fields;
    };

    struct AttackHitEffectResult__Fields {
        struct MessageBase_1__Fields _;
        uint32_t hitEffLevel_;
        float retreatStrength_;
        float airStrength_;
        float hitHaltTime_;
        float hitHaltTimeScale_;
        uint32_t originalHitEffLevel_;
    };

    struct AttackHitEffectResult {
        void* klass;
        MonitorData* monitor;
        struct AttackHitEffectResult__Fields fields;
    };

    //FNNBKNJJGNM__Fields
    struct AttackResult_1__Fields {
        struct MessageBase_1__Fields _;
        uint32_t attackerId_;
        uint32_t defenseId_;
        struct String* animEventId_;
        struct AbilityIdentifier_1* abilityIdentifier_;
        float damage_;
        bool isCrit_;
        void* hitCollision_;
        uint32_t hitPosType_;
        uint32_t endureBreak_;
        struct Vector_1* resolvedDir_;
        int32_t hitRetreatAngleCompat_;
        struct AttackHitEffectResult* hitEffResult_;
        uint32_t elementType_;
        bool useGadgetDamageAction_;
        uint32_t gadgetDamageActionIdx_;
        bool isResistText_;
        uint32_t criticalRand_;
        float elementAmplifyRate_;
        float damageShield_;
        bool muteElementHurt_;
        uint32_t amplifyReactionType_;
        uint32_t addhurtReactionType_;
        uint32_t bulletFlyTimeMs_;
        uint32_t attackCount_;
        uint32_t hashedAnimEventId_;
        uint32_t attackTimestampMs_;
        float endureDelta_;
        uint32_t targetType_;
        float elementDurabilityAttenuation_;
        uint32_t HGENJBMMFDH;
    };

    struct AttackResult_1 {
        void* klass;
        MonitorData* monitor;
        struct AttackResult_1__Fields fields;
    };

    enum class MotionState__Enum : int32_t {
        MotionNone = 0x00000000,
        MotionReset = 0x00000001,
        MotionStandby = 0x00000002,
        MotionStandbyMove = 0x00000003,
        MotionWalk = 0x00000004,
        MotionRun = 0x00000005,
        MotionDash = 0x00000006,
        MotionClimb = 0x00000007,
        MotionClimbJump = 0x00000008,
        MotionStandbyToClimb = 0x00000009,
        MotionFight = 0x0000000a,
        MotionJump = 0x0000000b,
        MotionDrop = 0x0000000c,
        MotionFly = 0x0000000d,
        MotionSwimMove = 0x0000000e,
        MotionSwimIdle = 0x0000000f,
        MotionSwimDash = 0x00000010,
        MotionSwimJump = 0x00000011,
        MotionSlip = 0x00000012,
        MotionGoUpstairs = 0x00000013,
        MotionFallOnGround = 0x00000014,
        MotionJumpUpWallForStandby = 0x00000015,
        MotionJumpOffWall = 0x00000016,
        MotionPoweredFly = 0x00000017,
        MotionLadderIdle = 0x00000018,
        MotionLadderMove = 0x00000019,
        MotionLadderSlip = 0x0000001a,
        MotionStandbyToLadder = 0x0000001b,
        MotionLadderToStandby = 0x0000001c,
        MotionDangerStandby = 0x0000001d,
        MotionDangerStandbyMove = 0x0000001e,
        MotionDangerWalk = 0x0000001f,
        MotionDangerRun = 0x00000020,
        MotionDangerDash = 0x00000021,
        MotionCrouchIdle = 0x00000022,
        MotionCrouchMove = 0x00000023,
        MotionCrouchRoll = 0x00000024,
        MotionNotify = 0x00000025,
        MotionLandSpeed = 0x00000026,
        MotionMoveFailAck = 0x00000027,
        MotionWaterfall = 0x00000028,
        MotionDashBeforeShake = 0x00000029,
        MotionSitIdle = 0x0000002a,
        MotionForceSetPos = 0x0000002b,
        MotionQuestForceDrag = 0x0000002c,
        MotionFollowRoute = 0x0000002d,
        MotionSkiffBoarding = 0x0000002e,
        MotionSkiffNormal = 0x0000002f,
        MotionSkiffDash = 0x00000030,
        MotionSkiffPoweredDash = 0x00000031,
        MotionDestroyVehicle = 0x00000032,
        MotionFlyIdle = 0x00000033,
        MotionFlySlow = 0x00000034,
        MotionFlyFast = 0x00000035,
        MotionNum = 0x00000036,
        OOFNNHKLEFE = 0x00000037,
        KMIGLMEGNOK = 0x00000038,
    };

    struct MotionInfo__Fields {
        struct MessageBase_1__Fields _;
        struct Vector_1* pos_;
        struct Vector_1* rot_;
        struct Vector_1* speed_;
        MotionState__Enum motionState;
        struct Google_Protobuf_Collections_RepeatedMessageField_1_Proto_Vector_* params_;
        struct Vector_1* refPos_;
        uint32_t refId_;
        uint32_t sceneTime_;
        uint32_t intervalVelocity_;
    };

    struct MotionInfo {
        void* klass;
        MonitorData* monitor;
        struct MotionInfo__Fields fields;
    };

    struct Singleton_1_MoleMole_EntityManager_ {
        struct Singleton_1_EntityManager___Class* klass;
        MonitorData* monitor;
    };

    enum class EntityManager_EntityManager_HeroEntityTeamState__Enum : int32_t {
        None = 0x00000000,
        MainAvatarInTeam = 0x00000001,
        MainAvatarNotInTeam = 0x00000002,
    };

    struct Matrix4x4 {
        float m00;
        float m10;
        float m20;
        float m30;
        float m01;
        float m11;
        float m21;
        float m31;
        float m02;
        float m12;
        float m22;
        float m32;
        float m03;
        float m13;
        float m23;
        float m33;
    };

    struct __declspec(align(8)) List_1_MoleMole_BaseEntity___Fields {
        struct BaseEntity__Array* _items;
        int32_t _size;
        int32_t _version;
        struct Object* _syncRoot;
    };

    struct List_1_MoleMole_BaseEntity_ {
        struct List_1_MoleMole_BaseEntity___Class* klass;
        MonitorData* monitor;
        struct List_1_MoleMole_BaseEntity___Fields fields;
    };

    // Entity fields
    struct __declspec(align(8)) EntityManager__Fields {
        bool useTickFunctionTick;
        struct EntityTickContext* _normalEntityTickContext;
        struct EntityTickContext* _lightInitEntityTickContext;
        struct EntityTickContext* _syncInitEntityTickContext;
        int32_t _unityThreadDoubleBufferIdx;
        struct Queue_1_BaseEntity___Array* _toDeleteEntitiesQueuesTripleBuffer;
        struct EntityManager_EntityManager_EntityTickListGroup__Array* _entityTickGroupDoubleBuffer;
        struct List_1_BaseEntity_* _entitiesLastFrame;
        struct Stack_1_EntityManager_EntityManager_EntityNotReadyReason___Array* _entityNotReadyReasonsDoubleBuffer;
        struct Dictionary_2_System_UInt32_EntityManager_EntityManager_AnimatorParamCache_* _entityAnimatorDefaultParamMap;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_Int32_List_1_BaseCommand_* _configID2cmdDic;
        struct EntityQueryGroup* _queryGroup;
        struct List_1_BaseEntity_* _entities;
        struct List_1_BaseEntity_* _entitiesToBeAdded;
        struct List_1_BaseEntity_* _entitiesToBeSafeReady;
        struct List_1_BaseEntity_* _entitiesToBeRemove;
        struct List_1_BaseComponent_* _preTickComponents;
        struct Queue_1_System_Int32_* _preTickComponentsEmptySlots;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_UInt32_System_Int32_* _preTickComponentDic;
        struct List_1_System_Int32_* _toBeRemovePreTickComponents;
        struct Dictionary_2_System_UInt32_BaseEntity_* _entityMap;
        struct Dictionary_2_System_UInt32_IBaseEntity_* _dummyEntityMap;
        struct ListAmortizedEntityTickHelper* _massiveEntities;
        struct Dictionary_2_UnityEngine_GameObject_System_UInt32_* _gameObjectDic;
        struct IList_1_VCAutoPickable_* _autoPickableComponents;
        struct IList_1_IAutoAttract_* _autoAttractComponents;
        float _localEntitiesCheckTime;
        struct List_1_BaseEntity_* _oldCachedEntityList;
        float _cachedEntitiesCheckTime;
        struct Dictionary_2_System_String_IList_1_BaseEntity_* _tagEntities;
        int32_t _ILBJGHHHJME_k__BackingField;
        int32_t _initComponnetCommonFramingTimer;
        int32_t _initLightComponentCommonFramingTimer;
        bool isEntityReadyOnly;
        struct ThreadTask_ProjectedHeightmapTask* _projectedHeightmapTask;
        int32_t NKDCAEIAHDA;
        struct Action* onPostDestroy;
        bool isDestroying;
        struct HashList_1_NPOKMLGJLAB_* MEDIEDBEJFE;
        int32_t _preIndex;
        struct Queue_1_Dictionary_2_System_UInt32_System_Int32_* _preTickDicPool;
        uint32_t _curTeamEntityID;
        uint32_t _globalTeamEntityID;
        uint32_t _curPlayTeamEntityID;
        struct List_1_System_UInt32_* _remoteTeamsEntitiesList;
        struct Dictionary_2_System_UInt32_System_UInt32_* _remoteTeamEntitiesDict;
        struct List_1_BaseEntity_* KHHEMGMBDAL;
        struct Dictionary_2_System_UInt32_BaseEntity_* _avatarEntityMap;
        struct List_1_BaseEntity_* HHAHCFHPDDP;
        uint32_t _curAvatarEntityID;
        struct List_1_BaseEntity_* _noCachedAvatarEntitys;
        struct List_1_BaseEntity_* _noCachedAvatarOnVehicleEntitys;
        uint64_t heroGuid;
        EntityManager_EntityManager_HeroEntityTeamState__Enum heroAvatarState;
        struct BaseEntity* _paimonEntity;
        struct CameraEntity* _mainCamera;
        bool _IPOCOIOMAEM_k__BackingField;
        struct Vector3 _IOCIKBGFKGH_k__BackingField;
        struct Matrix4x4 _KCBEIGODCLK_k__BackingField;
        struct CameraEntity* _subCamera;
        struct LevelEntity* _levelEntity;
        struct List_1_BaseEntity_* _entityListTemp;
        struct List_1_BaseEntity_* _combatEntitiesTemp;
        struct Dictionary_2_System_UInt32_System_Boolean_* _selectPickableShowDic;
        int32_t _SFWatchFlushRemoveEntityHandle;
        bool _nextForceFlushRemoveAllEntity;
        int32_t _forceFlushRemoveEntityFrame;
        bool _waitRemoveEntity;
        struct List_1_System_UInt32_* _hideEntityList;
        struct List_1_Config_ConfigEntityBlackGrp_* _curNpcBanConfigList;
        struct Dictionary_2_System_UInt32_List_1_System_UInt32_* JDBOOEMBLLL;
        struct AbilityProxyMgr* _abilityProxyMgr;
        struct EntityProxyBeforeUpdateTickTask* _proxyBeforeTask;
        struct Dictionary_2_BaseEntity_LMIDAOBMGGL_* KCKHKFBACJG;
        struct Dictionary_2_IIKHKAJJBOI_APFCHMKNECG_* OBMFDGNHFMK;
        struct Queue_1_BaseEntity_* _destroyReuseQueue;
        struct HashSet_1_System_UInt32_* _configIDBlackList;
        struct IGroup__Array* _taskGroups;
        struct List_1_UnityEngine_Vector3_* _sharedAvatarPositions;
        struct List_1_UnityEngine_Vector3_* _sharedRemoteAvatarPositions;
        struct Vector3 _sharedLocalAvatarPosition;
    };

    struct MoleMole_EntityManager {
        void* klass;
        MonitorData* monitor;
        struct EntityManager__Fields fields;
    };

    struct __declspec(align(8)) ConfigEntityPoint__Fields {
        struct String* _elementAbsorb;
        struct String* _elementPendant;
        struct String* _elementDrop;
        struct String* _bulletAim;
        struct String__Array* _hitPoints;
        struct String__Array* _selectedPoints;
    };

    struct ConfigEntityPoint {
        struct ConfigEntityPoint__Class* klass;
        MonitorData* monitor;
        struct ConfigEntityPoint__Fields fields;
    };

    struct __declspec(align(8)) ConfigEntity__Fields {
        struct ConfigEntityCommon* _common;
        struct ConfigHeadControl* _headControl;
        struct ConfigEntityPoint* _specialPoint;
        struct ConfigCustomAttackShape* _customAttackShape;
        struct ConfigModel* _model;
        struct ConfigDither* _dither;
        struct ConfigGlobalValue* _globalValue;
        struct ConfigEntityTags* _entityTags;
    };

    struct __declspec(align(8)) ConfigEntityTags__Fields {
        struct String__Array* _initTags;
    };

    struct ConfigEntityTags {
        struct ConfigEntityTags__Class* klass;
        MonitorData* monitor;
        struct ConfigEntityTags__Fields fields;
    };

    struct ConfigEntity {
        struct ConfigEntity__Class* klass;
        MonitorData* monitor;
        struct ConfigEntity__Fields fields;
    };

    struct ConfigEffectAttachShape {
        struct IPKPCAHLJMG__Class* klass;
        MonitorData* monitor;
    };

    struct __declspec(align(8)) ConfigHeadControl__Fields {
        bool _useHeadControl;
        struct SimpleSafeFloat maxYawDegreeRawNum;
        struct SimpleSafeFloat maxPitchDegreeRawNum;
        struct SimpleSafeFloat speedRawNum;
        struct SimpleSafeFloat weightSpeedRawNum;
        bool _useWhiteAnimStates;
        struct String__Array* _animStates;
        struct String__Array* _dontAnimStates;
    };

    // OOMADMNGOPK
    struct ConfigHeadControl {
        struct OOMADMNGOPK__Class* klass;
        MonitorData* monitor;
        struct ConfigHeadControl__Fields fields;
    };

    struct __declspec(align(8)) ConfigEntityCommon__Fields {
        struct ConfigEffectAttachShape* IJCEFOJNOHH;
        struct SimpleSafeFloat massRawNum;
        struct SimpleSafeFloat heightRawNum;
        struct SimpleSafeFloat modelHeightRawNum;
        struct SimpleSafeFloat viewSizeRawNum;
        struct SimpleSafeFloat shadowViewSizeRatioRawNum;
        struct SimpleSafeFloat overrideCullBoundsRadiusRawNum;
        bool _affectedByWorld;
        bool _checkInSurface;
        struct SimpleSafeFloat scaleRawNum;
        struct SimpleSafeFloat disableTickDistanceRawNum;
        struct SimpleSafeFloat forcePauseTickDistanceRawNum;
        bool _shouldPauseAnimatorBeforeReady;
        bool _canTriggerElementReactionText;
        bool _useGrassDisplacement;
        bool _muteElementStickUI;
        bool _hasAfterImage;
        bool _useDynamicBoneMultiParams;
        bool _enableCrashDamage;
        bool _clearAnimatorOnSetLightDeactive;
        bool _clearAIOnSetLightDeactive;
        bool _useFinalIK;
        struct SimpleSafeFloat AAFDECOKPNE;
        struct SimpleSafeFloat GIDINJKEKGG;
    };

    struct ConfigEntityCommon {
        struct ConfigEntityCommon__Class* klass;
        MonitorData* monitor;
        struct ConfigEntityCommon__Fields fields;
    };

    struct __declspec(align(8)) EntityExcelConfig__Fields {
        struct SimpleSafeUInt32 idRawNum;
        uint32_t _nameTextMapHash;
        uint8_t _prefabPathHashPre;
        uint32_t _prefabPathHashSuffix;
        uint8_t _prefabPathRemoteHashPre;
        uint32_t _prefabPathRemoteHashSuffix;
        uint8_t _controllerPathHashPre;
        uint32_t _controllerPathHashSuffix;
        uint8_t _controllerPathRemoteHashPre;
        uint32_t _controllerPathRemoteHashSuffix;
        struct SimpleSafeUInt32 campIDRawNum;
        struct String* _LODPatternName;
    };

    struct EntityExcelConfig {
        struct EntityExcelConfig__Class* klass;
        MonitorData* monitor;
        struct EntityExcelConfig__Fields fields;
    };

    enum class RemoveActorType__Enum : int32_t {
        NONE = 0x00000000,
        REMOVE = 0x00000001,
        REMOVE_WITH_DISAPPEAR = 0x00000002,
    };

    enum class ActorType__Enum : int32_t {
        INVALID = 0x00000000,
        BASE_ENTITY = 0x00000001,
        NPC_ACTOR = 0x00000002,
        QUEST_ACTOR = 0x00000003,
        GLOBAL_ACTOR = 0x00000004,
        GADGET_ACTOR = 0x00000005,
        SUB_GLOBAL_ACTOR = 0x00000006,
        CUTSCENE_ACTOR = 0x00000007,
        INTERACTION_ACTOR = 0x00000008,
        NPCGLOBAL_ACTOR = 0x00000009,
    };

    struct __declspec(align(8)) LocalEntityInfoData__Fields {
        int32_t _index_k__BackingField;
        uint32_t _entityId;
        ActorType__Enum _actorType_k__BackingField;
        struct String* _alias_k__BackingField;
        struct String* _metaPath_k__BackingField;
        uint32_t _configId_k__BackingField;
        struct Vector3 _initPos_k__BackingField;
        struct Vector3 _initEuler_k__BackingField;
        uint32_t _sceneId_k__BackingField;
        uint32_t _roomId_k__BackingField;
        uint32_t _questId_k__BackingField;
        uint32_t _level_k__BackingField;
        uint32_t _dropId_k__BackingField;
        float _scale_k__BackingField;
    };

    struct LocalEntityInfoData {
        struct LocalEntityInfoData__Class* klass;
        MonitorData* monitor;
        struct LocalEntityInfoData__Fields fields;
    };

    enum class GlobalVars_WorldType__Enum : int32_t {
        Invalid = -1,
        Login = 0x00000000,
        Home = 0x00000001,
        Level = 0x00000002,
        DevLevel = 0x00000003,
        BundleDownload = 0x00000004,
        LevelTestScene = 0x00000005,
        TestCutscene = 0x00000006,
        ScenicScanLevel = 0x00000007,
        TalkPreview = 0x00000008,
        ProfileEffects = 0x00000009,
        RagdollScene = 0x0000000a,
        MoveTestScene = 0x0000000b,
        PSPrepare = 0x0000000c,
    };

    struct __declspec(align(8)) GameWorld__Fields {
        struct String* _scenePath_k__BackingField;
        GlobalVars_WorldType__Enum _worldType_k__BackingField;
    };

    struct GameWorld {
        struct GameWorld__Class* klass;
        MonitorData* monitor;
        struct GameWorld__Fields fields;
    };

    struct GameManager__Fields {
        struct MonoBehaviour__Fields _;
        bool isDevLevel;
        bool workOffline;
        bool isOnlineMode;
        bool isUnloadResource;
        struct GameWorld* _curGameWorld;
        bool _shouldForceFinishObjectPoolWarmUp;
        int32_t _lastFixedUpdateFrameCount;
        bool _isToGoBackHome;
        bool _isToGoBundleDownload;
        uint64_t pauseApplicationTime;
        struct Coroutine* _setAndroidResolution;
        struct SchedulerMgr* _schedulerMgr;
        struct SchedulerGlobalMgr* _schedulerGlobalMgr;
    };

    struct GameManager__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct GameManager__StaticFields {
        struct GameManager* Instance;
        struct DelegateBridge* OAGELDJLOJD;
        struct DelegateBridge* NEABNMMILLI;
        struct DelegateBridge* KEOKLBODBLP;
        struct DelegateBridge* DEEMHHNNOEK;
        struct DelegateBridge* KIMMOGJPFFD;
        struct DelegateBridge* LBFLLENAFKB;
        struct DelegateBridge* IABPFHNPPCJ;
        struct DelegateBridge* BMEDOLOGBCB;
        struct DelegateBridge* CCMJFDDMCFG;
        struct DelegateBridge* BAFLDGOPNOO;
        struct DelegateBridge* MAIMNJNJDGC;
        struct DelegateBridge* BKILMOMOHAB;
        struct DelegateBridge* HNMMHCNFPCD;
        struct DelegateBridge* DACANBJAGPF;
        struct DelegateBridge* JGPNHNMDPDB;
        struct DelegateBridge* ADDDBIFJPFO;
        struct DelegateBridge* JHLAEBJBMOD;
        struct DelegateBridge* AHBOCPFBOCL;
        struct DelegateBridge* POFODBIGLFB;
        struct DelegateBridge* CDNGECKGDMH;
        struct DelegateBridge* DCOPNDDOBKC;
        struct DelegateBridge* OGMBELHIGBH;
        struct DelegateBridge* KHENDDJCHIP;
        struct DelegateBridge* NEEFOPMIMCF;
        struct DelegateBridge* CMGIEDELLDJ;
        struct DelegateBridge* DCKAELBHEEC;
        struct DelegateBridge* PNLGKJHENMN;
        struct DelegateBridge* MCONGDJILEF;
        struct DelegateBridge* PDIGKMFPAME;
        struct DelegateBridge* DLGKDHDBDEF;
        struct DelegateBridge* INLLOKNJEPG;
        struct DelegateBridge* EIMHAAKNEPG;
        struct DelegateBridge* PBLANCHOJAG;
        struct DelegateBridge* BGMPGGDLHJL;
        struct DelegateBridge* CLELPJPKLKF;
        struct DelegateBridge* GOCBMGBJNIM;
        struct DelegateBridge* GJDECCBHKDJ;
        struct DelegateBridge* EFBOILNAOGP;
        struct DelegateBridge* GGAGDELBNNO;
        struct DelegateBridge* FAFFFDMLIDM;
        struct DelegateBridge* PLOIIMCGGLJ;
        struct DelegateBridge* JMFLAJFLGAF;
        struct DelegateBridge* BLEKOLCNEOI;
        struct DelegateBridge* GJJMMCPAIOJ;
        struct DelegateBridge* FBPBBLIMCMH;
        struct DelegateBridge* KAFNJPDAOHE;
        struct DelegateBridge* DCKCMNEFOLB;
        struct DelegateBridge* NPNJEJGNKLP;
    };

    struct GameManager__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct GameManager__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct GameManager__VTable vtable;
    };


    struct GameManager {
        struct GameManager__Class* klass;
        MonitorData* monitor;
        struct GameManager__Fields fields;
    };

    struct Singleton_1__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        void* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
    };

    // PNEPINGJIGK__Enum
    enum class FacingMoveType__Enum : int32_t {
        ForwardOnly = 0x00000000,
        ForwardBackward = 0x00000001,
        FourDirection = 0x00000002,
        LeftRight = 0x00000003,
        AirBlend = 0x00000004,
    };

    // HFEHGGJADHF__Enum
    enum class WaterResult__Enum : int32_t {
        SAFE = 0x00000000,
        ALMOST_IN_OR_OUT_WATER = 0x00000001,
        BOUND_EXCEEDED = 0x00000002,
    };

    // JEILBENMJFJ__Enum
    enum class MonsterSizeType__Enum : int32_t {
        NormalHumanoidType = 0x00000000,
        StoopType = 0x00000001,
        StrongHumanoidType = 0x00000002,
        SlimeType = 0x00000003,
        OtherType = 0x00000063,
    };

    enum class PositionModifyState__Enum : int32_t {
        All = 0x00000000,
        Walk = 0x00000001,
        Run = 0x00000002,
        None = 0x00000003,
    };

    struct RaycastHit {
        struct Vector3 m_Point;
        struct Vector3 m_Normal;
        int32_t m_FaceID;
        int32_t m_InternalFaceID;
        float m_Distance;
        struct Vector2 m_UV;
        int32_t m_InstanceID;
        int32_t m_ColliderTag;
        int32_t m_SurfaceType;
        int32_t m_Layer;
        struct Collider* m_Collider;
    };

    struct Ray {
        struct Vector3 m_Origin;
        struct Vector3 m_Direction;
    };

    struct Nullable_1_Boolean_ {
        bool value;
        bool has_value;
    };

    struct __declspec(align(8)) BaseComponent__Fields {
        uint32_t componentRuntimeID;
        uint32_t entityRuntimeID;
        bool preTick;
        int32_t order;
        struct ComponentManager* _componentManager;
        struct BaseEntity* _entity;
        bool _isToBeRemoved;
        bool _enabled;
        bool hasTick;
        bool hasLateTick;
        bool _selfHasTick;
        bool _selfHasLateTick;
        bool _managerTick;
        bool _managerLateTick;
        struct List_1_System_Int32_* onEventIDs;
        struct List_1_System_Int32_* listenEventIDs;
        struct Int32__Array* _selfOnEventIDsCache;
        bool _isSelfOnEventIDsCached;
        struct Int32__Array* _selfListenEventIDsCache;
        bool _isSelfListenEventIDsCached;
        struct Action* preInitCallback;
        struct Action* initCallback;
        bool _canTickIfDisable;
        bool canTickIfDie;
        bool canHandleEventIfDie;
        bool _hasEnabledInited;
        int32_t _tickIntervalRatio;
        int32_t _lastTickInterval;
        struct Action_1_Single_* _tickMethodForEntityTickManager;
        struct Nullable_1_Boolean_ _isTickableForEntityTickManager;
        struct Action_1_Single_* _lateTickMethodForEntityTickManager;
        struct Nullable_1_Boolean_ _isLateTickableForEntityTickManager;
        struct Action_1_Single_* _latePreTickMethodForEntityTickManager;
        struct Nullable_1_Boolean_ _isLatePreTickableForEntityTickManager;
        bool needRetarget;
        bool isInited;
        bool isPreInited;
        bool hasCallEntityReady;
        bool _isDestroied;
        bool _listenEventValid_k__BackingField;
        struct Dictionary_2_System_Type_MoleMole_BaseComponentPlugin_* _pluginMap;
        struct List_1_MoleMole_BaseComponentPlugin_* _pluginList;
        struct List_1_MoleMole_BaseComponentPlugin_* _tickPlugins;
        struct List_1_MoleMole_BaseComponentPlugin_* _lateTickPlugins;
        struct Dictionary_2_System_Type_System_Int32_* _disableNoTickPlugins;
        struct Dictionary_2_System_Type_System_Int32_* _disableNoLateTickPlugins;
        struct Dictionary_2_System_Int32_MoleMole_BaseComponentPlugin_* _onEventPluginMap;
        struct Dictionary_2_System_Int32_List_1_MoleMole_BaseComponentPlugin_* _onEventPluginsMap;
        struct Dictionary_2_System_Int32_MoleMole_BaseComponentPlugin_* _listenEventPluginMap;
        struct Dictionary_2_System_Int32_List_1_MoleMole_BaseComponentPlugin_* _listenEventPluginsMap;
        bool _bIgnoreIntervalTick_k__BackingField;
        int32_t _greaterToDisableInterval_k__BackingField;
    };

    struct VCBase__Fields {
        struct BaseComponent__Fields _;
    };

    struct VCBase {
        struct FJBDIDKHCPN__Class* klass;
        MonitorData* monitor;
        struct VCBase__Fields fields;
    };

    struct VCBaseMove__Fields {
        struct VCBase__Fields _;
        struct EOOCBMLHHIF* _moveData;
        struct CMNPNEKDAIC* _configMove_k__BackingField;
        struct DFOFDDIAOID* referenceSystem;
        uint32_t referenceSystemId;
        uint32_t FOKGDKKILEH;
        struct Vector3 curLocalPositionRS;
        struct Vector3 lastLocalPositionRS;
        bool curRS;
        bool lastRS;
        struct Collider* referenceCol;
        bool referenceSystemNewAttached;
        struct Transform* _transform;
        struct EFEBGPHLEBK* controlData;
        struct Action* onFallOnGround;
        float dropGravityAcceleration;
        float _gravityScale;
        struct MCJJMMHFGPF__Array* ILFNNBCPBBM;
        bool _needFaceToAnimParam_k__BackingField;
        struct BOGIMDEGABM* _moveCollider;
        bool _moveColliderEnable;
        struct LAGCKJPGJIE* _velocityDetect;
        bool _IsInAirflowAcc_k__BackingField;
        struct Dictionary_2_System_Int32_System_Boolean_* _animatorParamCache;
        bool AOIMJFGIDJA;
        struct OEGJKMILHEO* _velocityForceMove;
        struct Vector3 _currentVelocityForce;
        int32_t _lastGetVelocityForceFrame;
        bool _keepInAirVelocityForce;
        struct PEFIHPNNKMH* syncPlugin;
    };

    struct VCBaseMove {
        struct VCBaseMove__Class* klass;
        MonitorData* monitor;
        struct VCBaseMove__Fields fields;
    };

    struct VCNonHumanoidMoveBase__Fields {
        struct VCBaseMove__Fields _;
        float maxMoveUphillSlope;
        float maxSlipSpeed;
        float yawSpeedRatio;
        uint32_t _moveLodValue;
        uint32_t _closeToGroundFrequency;
        uint32_t _currentCloseToGroundCount;
        struct Vector3 _lastDetectGroundPos;
        float avatarHeight;
        float avatarRadius;
        float _airDistance;
        struct Rigidbody* _rigidbody;
        bool canSteerInCurrentState;
        struct Animator* _animator;
        struct RuntimeAnimatorController* _cacheRuntimeAnimatorCtrl;
        float _currTilt;
        float _lastTimeTilt;
        struct EFEBGPHLEBK* _controlData;
        struct AnimatorController* _animatorController;
        bool _isInEmptyAnimatorControllerMode;
        struct Vector3 _lastPostion;
        float _currentGroundHeight;
        float _currentWaterHeight;
        bool _isInAir;
        bool _groundHit;
        bool _waterHit;
        struct RaycastHit _groundHitResult;
        struct Vector3 _extraCloseToGroundVelocity;
        struct Vector3 _cachedPosition;
        struct Vector3 _startPosition;
        struct Quaternion _cachedRotation;
        bool _setRotation;
        bool exactMove;
        struct Vector3 exactMoveTarget;
        struct Action_2_BaseEntity_Boolean_* _onInAirStateChanged;
        bool hasExtraGravityChange;
        float extraGravityChangeVal;
        struct Vector3 _dampVelocity;
        struct NAPAIPLOOAL* _lcAblityState;
    };


    struct VCAnimatorMove__Fields {
        struct VCNonHumanoidMoveBase__Fields _;
        struct FACKJKDBOPM* _cache;
        struct EIFKEDPIPCM* _data;
        struct Vector3 _lastHeadPosition;
        int32_t headIndex;
        int32_t cacheBonePosCount;
        struct VCAnimatorMove_FKMNEHFHOBL__Array* cachedPosArray;
        float stepTest;
        float changeLerp;
        bool _isInSlip;
        WaterResult__Enum _isInWater;
        struct Vector3 _teleportToPoint;
        struct Vector3 _teleportToFwd;
        bool _applyGravityInAir_k__BackingField;
        bool _isInAirMove;
        bool forceSetAirMove;
        bool remoteForceUseAnimatorVel;
        bool _enableAirTilt_k__BackingField;
        struct Vector3 _targetPointForTilt_k__BackingField;
        bool _airMoveFollowAnimationBySkill;
        bool _airMoveFollowAnimationByMove;
        bool _airMoveFollowAnimationByAnimation;
        bool _disableAnimatorTranslation;
        struct DKBOGPNAHKJ* _smoothSpeed;
        bool _moveOnGround;
        bool _moveOnWater;
        float _moveOnWaterDepth;
        float _targetYCoordinate;
        bool _hasTargetY;
        bool _targetWater;
        float _modelHeight;
        float _predictWaterHeight;
        float _predictGroundHeight;
        bool _predictWaterHit;
        bool _predictGroundHit;
        FacingMoveType__Enum _facingMoveType;
        MonsterSizeType__Enum _monsterSizeType;
        PositionModifyState__Enum _defaultPositionModifyState;
        struct Dictionary_2_System_UInt32_PCNJDLLFAGL_* _positionModifyStateMap;
        int32_t _returnDirectlyCount;
        bool _groundFollowAnimRotation;
        float _groundRotationScale;
        bool _handleAnimatorStateImmediately;
        struct Transform* _bip001;
        struct Quaternion _lastBipRotation;
        bool _setMoveOnWaterBeforePrepare;
        bool _preSetMoveOnWaterVal;
        float _pushColRadiusRatio;
        bool _destroyRockWhenInit;
        struct HKJJLCENDJM* _scenePropPlugin;
        struct BoneFollowMove* _boneChains;
        float _boneChainLerpRatio;
        int32_t _lastAnimHash;
        struct MonsterBoneChainAnimationData* _boneChainData;
        bool _boneChainMoveByAnimation;
        bool _enableBoneFollowMove;
        float _chainLengthRandomRangeUp;
        float _chainLengthRandomRangeLow;
        float _chainLengthRandomInterval;
        float _currentChainLengthRandomValue;
        float _lastChainLengthRandomTime;
        float extendDistLerpRatio;
        bool _enableVelocityDetect_k__BackingField;
        struct Vector2 _currentGeneralSteerAirPose;
        float flySmoothSpeed;
        int32_t dropHash;
        bool _currentIsIce;
        int64_t _currentIceId;
        float _groundRayTempExtraLength;
        bool _groundInfoRefreshed_k__BackingField;
        bool _isUsingAnimatorDeltaMode;
        bool canSyncMove;
        bool _firstTick;
        struct Vector3 _positionAfterInit;
        bool _syncFirstEnter;
        bool _syncFirstEnterNeedMove;
        bool _lastCanSyncMove;
        float _cannotSyncMoveTime;
        struct Vector3 _syncAirMoveVelocity;
        struct Vector3 _syncVelocity;
        struct GJPJPKFOHNG* _vcSyncAnimator;
        MotionState__Enum _lastNonStandbyMotion;

    };

    struct VCAnimatorMove {
        struct VCAnimatorMove__Class* klass;
        MonitorData* monitor;
        struct VCAnimatorMove__Fields fields;
    };

    enum class DieStateFlag__Enum : int32_t {
        None = 0x00000000,
        FrozenToDeath = 0x00000001,
        BurningToAshes = 0x00000002,
        DieFall = 0x00000003,
        DieDrawn = 0x00000004,
        DieAbyss = 0x00000005,
        Broken = 0x00000006,
        PetrifiedToDeath = 0x00000007,
    };

    struct LCBase__Fields {
        struct BaseComponent__Fields _;
        struct Dictionary_2_System_Int32_MoleMole_BaseComponentPlugin_* _onEventResolvedPluginMap;
        struct Dictionary_2_System_Int32_List_1_MoleMole_BaseComponentPlugin_* _onEventResolvedPluginsMap;
        struct List_1_System_Int32_* onEventResolvedIDs;
        struct Int32__Array* _selfOnEventResolvedIDsCache;
        bool _isSelfOnEventResolvedIDsCached;
    };

    struct LCBaseCombat_AttackTarget {
        uint32_t runtimeID;
        struct String* lockedPoint;
        int32_t MBCDNGIFGDD;
    };

    struct LCBaseCombat__Fields {
        struct LCBase__Fields _;
        struct CombatProperty* _combatProperty_k__BackingField;
        struct Config_ConfigCombat* configCombat;
        struct Action_1_LCBaseCombat_* onHPChanged;
        bool needCallHpChanged;
        struct Proto_MassiveEntityElementOpBatchNotify* massiveOpBatch;
        DieStateFlag__Enum dieStateFlag;
        TargetType__Enum targetType;
        bool _addToCombatEntities;
        struct VCBaseMove_1* _vcCombat;
        struct Dictionary_2_System_UInt32_LCBaseCombat_CombatCollision_* _attackeeEntityIds;
        uint32_t _lastTriggerAttackeeEntityId;
        int32_t _attackTagTriggeredFrameCount;
        struct HashSet_1_System_String_* _attackTagTriggeredThisFrame;
        struct LCBaseCombat_AttackTarget _attackTarget;
        bool _isSafeDestroied;
        float _recoverEndureTime;
        struct LCAttackAttenuationPlugin* _attackAttenuation;
        struct Config_ConfigCombatLock* _combatLock_k__BackingField;
        struct Config_ChangeLockTypeMixin* changeLockType;
    };

    struct LCBaseCombat {
        struct LCBaseCombat__Class* klass;
        MonitorData* monitor;
        struct LCBaseCombat__Fields fields;
    };

    enum class EvtFallOnGround_GroundType__Enum : int32_t {
        Land = 0x00000000,
        Water = 0x00000001,
        LandUnderWater = 0x00000002,
    };

    struct EvtFallOnGround__Fields {
        struct BaseEvent__Fields _;
        EvtFallOnGround_GroundType__Enum groundType;
        struct Vector3 velocity;
        float waterDepth;
    };

    struct EvtFallOnGround {
        struct EvtFallOnGround__Class* klass;
        MonitorData* monitor;
        struct EvtFallOnGround__Fields fields;
    };

    struct Config_RocketJumpExt {
        struct SimpleSafeFloat xzMultiplierRawNum;
        struct SimpleSafeFloat yMultiplierRawNum;
    };

    enum class Config_BodyType__Enum : int32_t {
        BODY_NONE = 0x00000000,
        BODY_BOY = 0x00000001,
        BODY_GIRL = 0x00000002,
        BODY_LADY = 0x00000003,
        BODY_MALE = 0x00000004,
        BODY_LOLI = 0x00000005,
    };

    struct HumanoidMoveFSMGoUpstairsState_PoseParameter {
        float length;
        float startRotate;
        float endRotate;
        float closeToGround;
        float enableMove;
        float enableLeftFootIK;
        float enableRightFootIK;
        float animatorPose;
        float distUp;
        float distForward;
        bool enable50Blend;
    };

    struct VCHumanoidMove__Fields {
        struct VCBaseMove__Fields _;
        Config_BodyType__Enum moveModelType;
        float minClimbSlope;
        float maxClimbSlope;
        float maxMoveSlope;
        float minSlipSlope;
        float upstairTanConst;
        float slipDropThreshold;
        float maxSlipSpeed;
        float slipAcceleration;
        float slipRapidDecelerationSlope;
        float slipRapidDecelerationRatio;
        float slipHaltSlope;
        float waterfallExtraDownAngle;
        float dropCliffAngleThreshold;
        float dropLandLightMaxSpeed;
        float dropLandMiddleMaxSpeed;
        float yawSpeedRatio;
        float swimYawSpeedRatio;
        float swimDashYawSpeedRatio;
        float startSwimHeightRatio;
        float stopSwimHeightRatio;
        float SwimHeightRatio;
        float airToSwimHeightRatio;
        float swimEnableSprintHeightRatio;
        float climbCloseToGroundDist;
        float hipOffsetFromIK;
        float _avatarHeight_k__BackingField;
        float avatarModelHeight;
        float avatarModelClimbHeight;
        float avatarWaitToheadHeight;
        float _avatarShoesHeight_k__BackingField;
        float _avatarRadius_k__BackingField;
        float _avatarHeadExtraHeight_k__BackingField;
        float moveSphereCastRadius;
        struct HumanoidMoveFSMGoUpstairsState_PoseParameter climbToStandbyHard;
        struct HumanoidMoveFSMGoUpstairsState_PoseParameter climbToStandbyMiddle;
        struct HumanoidMoveFSMGoUpstairsState_PoseParameter climbToStandbyLight;
        struct HumanoidMoveFSMGoUpstairsState_PoseParameter jumpUpstairs;
        struct HumanoidMoveFSMGoUpstairsState_PoseParameter climbtoStandbyGentle;
        struct AnimationCurve* jumpUpstairsHighCurve;
        struct AnimationCurve* jumpUpstairsLowCurve;
        struct AnimationCurve* jumpUpstairsHighZCurve;
        struct AnimationCurve* jumpUpstairsLowZCurve;
        struct AirRigidbody* _airRigidbody_k__BackingField;
        struct Rigidbody* dummyRigidbody;
        struct MonoAnimationIKEventHelper* animatorMoveHelper;
        struct HeightmapPlugin* heightmap;
        float closeToLadderDist;
        struct String* animatorTriggerOnLanded;
        struct Animator* animator;
        struct AnimatorController* animatorController;
        float sprintCheckInterval;
        float muteSprintInterval;
        struct VCHumanoidMove_StandbyIKParams__Array* standbyIKParams;
        struct Rigidbody* _rigidbody;
        struct Vector3 _center;
        int32_t _rotationFrame;
        bool applyGravityExternal;
        struct VCHumanoidMoveConfig* _moveConfig;
        struct RuntimeAnimatorController* _cacheRuntimeAnimatorCtrl;
        struct HumanoidMoveFSM* _humanoidMoveFSM;
        struct HumanoidMoveEffectPlugin* _effectPlugin;
        struct VCLevel* vcLevel;
        struct LevelMoveScenePropPlugin* _scenePropPlugin;
        struct VCAvatarPerform* vcPerform;
        float orthogonalVelocityRatio;
        struct VCHumanoidMoveData* _humanoidMoveData;
        struct Proto_MotionInfo* _motionInfo;
        struct Config_RocketJumpExt rocketJumpSetting;
        float runStopVelocityRatio;
        struct Transform* moveHeadTrans;
        struct Transform* climbHeadTrans;
        struct Transform* footTrans;
        struct Transform* waistTrans;
        struct Transform* kneeTrans;
        struct AvatarDataItem* avatarData;
        bool isJamedOverMonster;
        float overrideMoveSpeedRatio;
        int32_t _lastAnimatorStateShortNameHash;
        bool _needFaceToAnimParamEver;
        struct LCAbilityState* lcAblityState;
        struct VCAvatarEquipController* _equipController;
        struct Vector3 repeatlySetPos;
        int32_t repeatlySetPosFrameCount;
        struct Collider__Array* tempCollider;
        uint64_t disableChangeAvatarTime;
        int32_t _lastCheckDynamicBarrierFrame;
        struct HashSet_1_System_UInt32_* _ignoreCollisionEntities;
        struct HashSet_1_System_UInt32_* _nearbyDynamicBarriers;
        struct Vector3 _lastCheckDynamicBarrierPostion;
    };

    struct VCHumanoidMove {
        struct VCHumanoidMove__Class* klass;
        MonitorData* monitor;
        struct VCHumanoidMove__Fields fields;
    };

    enum class InteractionType__Enum : int32_t {
        NONE = 0x00000000,
        DIALOG = 0x00000001,
        DIALOG_NEXT = 0x00000002,
        DIALOG_FINISH = 0x00000003,
        DIALOG_SELECT = 0x00000004,
        BODY_LANG = 0x00000005,
        STEER_TO = 0x00000006,
        LOOK_AT = 0x00000007,
        LOOK_AT_EYECTRL = 0x00000008,
        CAMERA_MOVE = 0x00000009,
        SOUND = 0x0000000a,
        CUTSCENE = 0x0000000b,
        SHOP_EXCHANGE = 0x0000000c,
        GADGET_TOUCH = 0x0000000d,
        EMO_SYNC = 0x0000000e,
        UI_TRIGGER = 0x0000000f,
        EMOTION = 0x00000010,
        VISIBLE = 0x00000011,
        LUA_ACTION = 0x00000012,
        BLACK_SCREEN = 0x00000013,
        GODDESS = 0x00000014,
        SHOW_MESSAGE = 0x00000015,
        CAMERA_FOCUS = 0x00000016,
        DIALOG_CLEAR = 0x00000017,
        AUDIO_PLAY = 0x00000018,
        VIDEO_PLAY = 0x00000019,
        CAMERA_DOF = 0x0000001a,
        MOVE_TO = 0x0000001b,
        REQUEST_MSG = 0x0000001c,
        CAMERA_SHAKE = 0x0000001d,
        EMOJI_BUBBLE = 0x0000001e,
        TIME_PROTECT = 0x0000001f,
        SIMPLE_BLACK_SCREEN = 0x00000020,
        SIMPLE_UI_SHOW = 0x00000021,
        OPEN_BLOSSOM_MARK = 0x00000022,
        SPEECH_BUBBLE = 0x00000023,
        EMOTION_TEMPLATE = 0x00000024,
        SIT_OR_STAND = 0x00000025,
        PLAY_EFFECT = 0x00000026,
        TELEPORT_TO = 0x00000027,
        FIRST_SIGHT = 0x00000028,
        SET_ANIMATOR = 0x00000029,
        PLAY_POST_EFFECT = 0x0000002a,
        PLAY_FRAME_FACE_ANIMATION = 0x0000002b,
        HIDE_WIDGET_PET = 0x0000002c,
        LOCAL_GADGET_OP = 0x0000002d,
        PLAY_UI_EFFECT = 0x0000002e,
        SET_PLAYER_NPC_ENERGY_TYPE = 0x0000002f,
        CHANGE_NPC_MAT = 0x00000030,
        Other = 0x00000031,
    };

    struct __declspec(align(8)) BaseInterAction__Fields {
        InteractionType__Enum _type;
        uint32_t _mainQuestId;
        struct ConfigBaseInterAction* _cfg;
        struct InterActionGrp* _interGrp;
        bool _isFromExternal;
        struct OAMGPEEJGJL* _inter;
        struct LCBaseIntee* _intee;
        bool _isStarted;
        bool _isFinished;
    };

    //PONANPEDGNL__Fields
    struct DialogNextAction__Fields {
        struct BaseInterAction__Fields _;
        bool _insert;
        uint32_t _nextTalkID;
    };

    //PONANPEDGNL
    struct DialogNextAction {
        struct PONANPEDGNL__Class* klass;
        MonitorData* monitor;
        struct DialogNextAction__Fields fields;
    };

    enum class OLIGMHIBFPC__Enum : int32_t {
        None = 0x00000000,
        Debug = 0x00000001,
        Quest = 0x00000002,
        QuestCustom = 0x00000003,
        Talk = 0x00000004,
        Home = 0x00000005,
        TalkPreperform = 0x00000006,
        Daily = 0x00000007,
        ForceCache = 0x00000008,
        AnimeGroup = 0x00000009,
    };

    struct KAMMJKAFCMA {
        OLIGMHIBFPC__Enum LKBCPMNLDGM;
        uint32_t JNAIAKGGLDL;
    };

    struct MoleMole_EntityHandle_AvatarEntity_ {
        uint32_t runtimeID;
        struct AvatarEntity* _entityRef;
    };

    enum class RigidbodyConstraints__Enum : int32_t {
        None = 0x00000000,
        FreezePositionX = 0x00000002,
        FreezePositionY = 0x00000004,
        FreezePositionZ = 0x00000008,
        FreezeRotationX = 0x00000010,
        FreezeRotationY = 0x00000020,
        FreezeRotationZ = 0x00000040,
        FreezePosition = 0x0000000e,
        FreezeRotation = 0x00000070,
        FreezeAll = 0x0000007e,
    };

    // KNINMIIGGLK__Fields
    struct CharacterEntity__Fields {
        struct BaseEntity__Fields _;
        struct Vector3 _originLocalPosRoot;
        struct Vector3 _originLocalEulerRoot;
        struct Vector3 _originLocalScaleRoot;
        RigidbodyConstraints__Enum HIEIEAJOLFK;
        int32_t GPOIKBAPLOK;
        struct Transform* _bipTrans;
    };

    // KNINMIIGGLK
    struct CharacterEntity {
        struct KNINMIIGGLK__Class* klass;
        MonitorData* monitor;
        struct CharacterEntity__Fields fields;
    };

    // CAJECMIFAOJ__Fields
    struct AvatarEntity__Fields {
        struct CharacterEntity__Fields _;
        uint64_t guid;
        bool isSupporting;
        struct LIBBCAIJOGO_System_Boolean_* _activeStack;
        struct List_1_System_UInt32_* _childrenRuntimeIds;
        struct List_1_System_UInt32_* _descendantsRuntimeIds;
        bool _attackModeAuto;
    };

    // CAJECMIFAOJ
    struct AvatarEntity {
        struct CAJECMIFAOJ__Class* klass;
        MonitorData* monitor;
        struct AvatarEntity__Fields fields;
    };

    struct InteractionAvatarEntityProxy {
        struct CFHMEBOKAKH__Class* klass;
        MonitorData* monitor;
    };

    enum class AnimatorCullingMode__Enum : int32_t {
        AlwaysAnimate = 0x00000000,
        CullUpdateTransforms = 0x00000001,
        CullCompletely = 0x00000002,
    };

    struct LCBaseIntee__Fields {
        struct LCBase__Fields _;
        struct String* _triggerShapeIn;
        float _triggerShapeInHeight;
        struct String* _triggerShapeOut;
        float _triggerShapeOutHeight;
        struct Vector3 _triggerShapeInOffset;
        struct Vector3 _triggerShapeOutOffset;
        struct String* _triggerShapeFreeInteraction;
        float _triggerShapeFreeInteractionHeight;
        struct Vector3 _triggerShapeFreeInteractionOffset;
        struct Action_2_MoleMole_ILuaActor_MoleMole_ILuaActorCollisionInfo_* OnPushCollider;
        struct InteeShareTaskData* _interShareTaskData;
        struct LCBaseInter* _inter;
        struct LCBaseInter* _preInter;
        struct LCExtraInterAction* _extraAction;
        struct VCBaseHeadController* _headCtrl;
        bool _disableHeadCtrl_k__BackingField;
        bool _isTalking;
        uint32_t curTalkId;
        uint32_t _curPriority;
        RemoveActorType__Enum _removeType;
        bool _isInterDisable;
        bool _isLuaInterDisable;
        struct Action_1_MoleMole_LCBaseIntee_* OnFieldEnterHandler;
        struct Action_1_MoleMole_LCBaseIntee_* OnFieldBtnHandler;
        struct Action_1_MoleMole_LCBaseIntee_* OnFieldExitHandler;
        bool useTrigger;
        bool useInteractionTrigger;
        bool usePushCollider;
        bool useHeadControlTrigger;
        float _triggerRadius;
        float _interactionTriggerRadius;
        float _headCtrlTriggerRadius;
        uint32_t curPerformTalkId;
        bool _triggerEnter;
        bool _interactionTriggerEnter;
        bool _prePerformTriggerEnter;
        bool _headCtrlTriggerEnter;
        bool _isLookAtOnly;
        struct GameObject* _colliderObj;
        struct VCSpeechBubblePlugin* _speechBubble;
        AnimatorCullingMode__Enum _originalMode;
    };

    struct LCBaseIntee {
        struct LCBaseIntee__Class* klass;
        MonitorData* monitor;
        struct LCBaseIntee__Fields fields;
    };

    enum class TalkBeginWay__Enum : int32_t {
        TALK_BEGIN_NONE = 0x00000000,
        TALK_BEGIN_AUTO = 0x00000001,
        TALK_BEGIN_MANUAL = 0x00000002,
    };

    // GECLMNOMDKD__Enum
    enum class PlayMode__Enum_1 : int32_t {
        PLAY_MODE_ALL = 0x00000000,
        PLAY_MODE_SINGLE = 0x00000001,
        PLAY_MODE_MULTIPLE = 0x00000002,
        PLAY_MODE_HOST = 0x00000003,
        PLAY_MODE_GUEST = 0x00000004,
    };

    // KPBHGKOJDML__Enum
    enum class LogicType__Enum : int32_t {
        LOGIC_NONE = 0x00000000,
        LOGIC_AND = 0x00000001,
        LOGIC_OR = 0x00000002,
        LOGIC_NOT = 0x00000003,
        LOGIC_A_AND_ETCOR = 0x00000004,
        LOGIC_A_AND_B_AND_ETCOR = 0x00000005,
        LOGIC_A_OR_ETCAND = 0x00000006,
        LOGIC_A_OR_B_OR_ETCAND = 0x00000007,
        LOGIC_A_AND_B_OR_ETCAND = 0x00000008,
    };

    enum class TalkHeroType__Enum : int32_t {
        TALK_HERO_LOCAL = 0x00000000,
        TALK_HERO_MAIN = 0x00000001,
    };

    enum class TalkLoadType__Enum : int32_t {
        TALK_NORMAL_QUEST = 0x00000000,
        TALK_BLOSSOM = 0x00000001,
        TALK_ACTIVITY = 0x00000002,
        TALK_COOP = 0x00000003,
        TALK_GADGET = 0x00000004,
    };

    enum class TalkMarkType__Enum : int32_t {
        TALK_MARK_NONE = 0x00000000,
        TALK_MARK_COMMON = 0x00000001,
        TALK_MARK_HIDE = 0x00000002,
    };

    // GOPFNFNPLGP__Fields
    struct __declspec(align(8)) ConfigTalkScheme__Fields {
        uint32_t _id;
        TalkBeginWay__Enum _beginWay;
        PlayMode__Enum_1 _activeMode;
        LogicType__Enum _beginCondComb;
        struct TalkCondEx__Array* _beginCond;
        uint32_t _priority;
        struct UInt32__Array* _nextTalks;
        struct UInt32__Array* _nextRandomTalks;
        int32_t _showRandomTalkCount;
        uint32_t _initDialog;
        uint32_t _decoratorID;
        struct UInt32__Array* _npcId;
        struct String* _performCfg;
        TalkHeroType__Enum _heroTalk;
        TalkLoadType__Enum _loadType;
        uint32_t _questId;
        struct UInt32__Array* _extraLoadMarkId;
        uint64_t _assetIndex;
        bool _dontBlockDaily;
        struct UInt32__Array* _participantId;
        struct String* _prePerformCfg;
        bool _stayFreeStyle;
        bool _enableCameraDisplacement;
        bool _lockGameTime;
        TalkMarkType__Enum _talkMarkType;
        bool _questIdleTalk;
        bool _lowPriority;
        struct AIJNLBLCLCI__Array* _finishExec;
        struct Int32__Array* _prePerformFreeStyleList;
        struct Int32__Array* _freeStyleList;
        struct UInt32__Array* LFMNEFDCDND;
        bool setToBeRemove;
        struct List_1_System_UInt32_* _nextValidTalkList;
        struct List_1_System_UInt32_* _nextAfterRandomTalkList;
    };

    // GOPFNFNPLGP
    struct ConfigTalkScheme {
        struct GOPFNFNPLGP__Class* klass;
        MonitorData* monitor;
        struct ConfigTalkScheme__Fields fields;
    };

    struct __declspec(align(8)) List_1_MoleMole_BaseInterAction___Fields {
        struct BaseInterAction__Array* _items;
        int32_t _size;
        int32_t _version;
    };

    struct List_1_MoleMole_BaseInterAction_ {
        struct List_1_MoleMole_BaseInterAction___Class* klass;
        MonitorData* monitor;
        struct List_1_MoleMole_BaseInterAction___Fields fields;
    };

    // ELIBDKPELPD__Fields
    struct __declspec(align(8)) InterActionGrp__Fields {
        uint64_t groupId;
        uint64_t nextGroupId;
        bool isKeyList;
        struct List_1_MoleMole_BaseInterAction_* _interActionList;
        bool _isStarted;
    };

    // ELIBDKPELPD
    struct InterActionGrp {
        struct ELIBDKPELPD__Class* klass;
        MonitorData* monitor;
        struct InterActionGrp__Fields fields;
    };

    struct __declspec(align(8)) LinkedListNode_1_InterActionGrp___Fields {
        struct InterActionGrp* item;
        struct LinkedList_1_InterActionGrp_* container;
        struct LinkedListNode_1_InterActionGrp_* forward;
        struct LinkedListNode_1_InterActionGrp_* back;
    };

    struct LinkedListNode_1_InterActionGrp_ {
        struct LinkedListNode_1_ELIBDKPELPD___Class* klass;
        MonitorData* monitor;
        struct LinkedListNode_1_InterActionGrp___Fields fields;
    };

    struct __declspec(align(8)) LinkedList_1_InterActionGrp___Fields {
        uint32_t count;
        uint32_t version;
        struct Object* syncRoot;
        struct LinkedListNode_1_InterActionGrp_* first;
        struct SerializationInfo* si;
    };

    struct LinkedList_1_InterActionGrp_ {
        struct LinkedList_1_ELIBDKPELPD___Class* klass;
        MonitorData* monitor;
        struct LinkedList_1_InterActionGrp___Fields fields;
    };

    struct __declspec(align(8)) InteractionManager__Fields {
        bool _checkInteruptCoopOnFinish;
        struct InteractionAvatarEntityProxy* _localAvatarProxy;
        struct MoleMole_EntityHandle_AvatarEntity_ _simpleTalkActionAvatarHandle;
        struct Action_1_DKOJFNPLGIA_* _interactionInteeCB;
        bool _isManulAttackMode;
        struct Dictionary_2_System_UInt32_MoleMole_Config_ConfigInterActor_* _returnDailyNpcConfigDic;
        struct HashSet_1_System_UInt32_* _participantDic;
        struct Dictionary_2_System_UInt32_System_UInt32_* _avatarDialogIntees;
        struct Dictionary_2_System_String_System_String_* _tmpAlias2Real;
        struct Dictionary_2_System_String_MoleMole_LCBaseIntee_* _alias2intee;
        bool _canShowAvatarEffectWhenTalkStart;
        struct KAMMJKAFCMA _curLoadFreeStyleReason;
        struct Dictionary_2_System_UInt32_System_Int32__2* _curLoadFreeStyleDic;
        bool _isLoadingFreeStyle;
        uint32_t _curLoadFreeStyleQuestId;
        struct ILuaActor* _currInterActor;
        struct Action_2_MoleMole_ILuaActor_Int32_* StartInterEvent;
        struct Action_2_MoleMole_ILuaActor_Int32_* FinishInterEvent;
        struct LCBaseIntee* _mainIntee;
        int32_t _keyInterCnt;
        bool _hasKeyPre;
        bool _havEndFade;
        float _endFadeInTime;
        float _endFadeOutTime;
        bool _inEndFade;
        bool _inStartFade;
        bool _talkLoading;
        bool _voiceLoading;
        bool _isLockGameTime;
        bool _isInteeReadyChecking;
        bool _isDelayClear;
        struct String* _interEntityBanConfig;
        bool _isFromPerformConfig;
        struct LinkedList_1_InterActionGrp_* _keyInterList;
        struct Dictionary_2_System_UInt64_LinkedListNode_1_ELIBDKPELPD_* _idInterDic;
        struct LinkedListNode_1_InterActionGrp_* _currInterGrp;
        struct List_1_ELIBDKPELPD_* _freeInterList;
        struct Dictionary_2_System_UInt32_List_1_ELIBDKPELPD_* _priorityBtnDic;
        uint32_t _triggeringEntityID;
        bool _edtTalkWaiting;
        struct List_1_System_UInt32_* _evtInterFinishList;
        struct Action* _keyListFinishHandler;
        struct Action* _keyListPreFinishHandler;
        struct Action* _levelLoadFinishHandler;
        struct InteractionManager_NpcInteractionRequestCache* _npcInteractionRequest;
        struct GBPAPDPGOGC__Array* _keyInterSystems;
        struct GBPAPDPGOGC__Array* _keyUsingSystems;
        struct GBPAPDPGOGC__Array* _freeInterSystems;
        struct GBPAPDPGOGC__Array* _freeUsingSystems;
        struct FBLKAMGAEBK_GBPAPDPGOGC_* _systemListPool;
        struct List_1_MoleMole_LCBaseIntee_* _candidateInteeAddList;
        struct List_1_GOPFNFNPLGP_* _candidateTalkCfgList;
        struct List_1_MoleMole_LCBaseIntee_* _candidateInteeRemoveList;
        struct HashSet_1_System_UInt32_* _currCandidateIdSet;
        struct Dictionary_2_MoleMole_LCBaseIntee_FBLKAMGAEBK_PCAHMKPNKKE_* _curRunningPreTalkDic;
        struct FBLKAMGAEBK_MoleMole_InteractionManager_PreTalkPerformContext_* _curRunningPreTalkList;
        struct EEEOCECMOIP_MoleMole_InteractionManager_PreTalkPerformContext_* _talkPerformContextPool;
        struct List_1_System_UInt32_* _autoBanNpcRuntimeIdList;
        struct DAIJGKCPFFG* _autoTalkVoiceResponder;
        struct Dictionary_2_System_String_List_1_System_Int32_* _effectHandlerDic;
        struct Dictionary_2_System_String_KeyValuePair_2_System_UInt32_UnityEngine_GameObject_* _uiEffectDic;
    };

    struct InteractionManager {
        struct InteractionManager__Class* klass;
        MonitorData* monitor;
        struct InteractionManager__Fields fields;
    };

    struct BaseInterAction {
        struct BaseInterAction__Class* klass;
        MonitorData* monitor;
        struct BaseInterAction__Fields fields;
    };

    struct __declspec(align(8)) ConfigBaseInterAction__Fields
    {
        InteractionType__Enum _type;
        float _delayTime;
        float _duration;
        struct String__Array* _aliasList;
        bool _checkNextImmediately;
    };

    struct ConfigBaseInterAction {
        struct ConfigBaseInterAction__Class* klass;
        MonitorData* monitor;
        struct ConfigBaseInterAction__Fields fields;
    };

    struct __declspec(align(8)) MessageInfo__Fields {
        struct Dictionary_2_System_UInt16_System_String_* _cmdNameDict;
        struct Dictionary_2_System_String_System_UInt16_* _cmdIdDict;
        struct Dictionary_2_System_UInt16_System_UInt32_* _cmdChannelIdDict;
        struct Dictionary_2_System_UInt16_MoleMole_MessageInfo_AGLNJLPBPMO_* _cmdAllocFunc;
        struct HashSet_1_System_UInt16_* _cmdIsReliableSet;
        struct HashSet_1_System_UInt16_* _cmdIsAllowedSet;
    };

    struct MessageInfo {
        struct MessageInfo__Class* klass;
        MonitorData* monitor;
        struct MessageInfo__Fields fields;
    };

    struct KcpPacket_1 {
        void* data;
        uint32_t dataLen;
    };

    enum class PacketStatus__Enum : int32_t {
        PACKET_CORRECT = 0x00000001,
        PACKET_NOT_COMPLETE = 0x00000002,
        PACKET_NOT_CORRECT = 0x00000003,
        PACKET_BUFF_IS_NULL = 0x00000004,
        PACKET_BUFF_LEN_SHORT = 0x00000005,
        PACKET_HEAD_MAGIC_ERROR = 0x00000006,
        PACKET_TAIL_MAGIC_ERROR = 0x00000007,
    };

    struct __declspec(align(8)) JDBPGPCCJJP__Fields {
        struct JPIOKGLLCPH* Head;
        struct MessageBase_1* Body;
        bool _selfAllocBody;
        uint32_t ODEHIAOBAKE;
        uint32_t _packetSize;
        struct LockFreeQueue* _allocStack;
        int32_t lastStack;
        uint16_t _CmdId_k__BackingField;
    };

    struct Packet {
        struct JDBPGPCCJJP__Class* klass;
        MonitorData* monitor;
        struct JDBPGPCCJJP__Fields fields;
    };

    enum class KcpEventType__Enum : int32_t {
        EventNotSet = -1,
        EventConnect = 0x00000000,
        EventConnectFailed = 0x00000001,
        EventDisconnect = 0x00000002,
        EventRecvMsg = 0x00000003,
        EventCount = 0x00000004,
    };


    struct KcpEvent {
        KcpEventType__Enum type;
        uint32_t token;
        uint32_t data;
        struct KcpPacket_1* packet;
    };

    struct ClientKcpEvent {
        struct KcpEvent _evt;
    };

    // EJGKINLFJKF__Enum
    enum class UIType__Enum : int32_t {
        Page = 0x00000000,
        SpecialDialog = 0x00000001,
        SuspendBar = 0x00000002,
        Dialog = 0x00000003,
        Root = 0x00000004,
    };

    // JBMBEBFMJAO__Enum
    enum class ContextQueueType__Enum : int32_t {
        NONE = 0x00000000,
        MAIN_PAGE_LEFT = 0x00000001,
        MAIN_PAGE_TOP = 0x00000002,
        MAIN_PAGE_LEFT_QUEST = 0x00000003,
        MAIN_PAGE_MIDDLE_QUEST = 0x00000004,
        MAIN_TOP_HIGH_PRIORITY = 0x00000005,
    };

    // IFIGONNBKLP__Enum
    enum class CanvasType__Enum : int32_t {
        Invalid = 0x00000000,
        InLevelCanvas = 0x00000001,
        RootCanvas = 0x00000002,
    };

    // PJGDFNLLFMO__Enum
    enum class ContextLoadState__Enum : int32_t {
        UnLoaded = 0x00000000,
        Cached = 0x00000001,
        Loading = 0x00000002,
        Loaded = 0x00000003,
        UnLoading = 0x00000004,
    };

    // IHKGPINHAJG__Enum
    enum class ContextViewState__Enum : int32_t {
        Active = 0x00000000,
        Inactive = 0x00000001,
        Hiding = 0x00000002,
    };

    // IHIAPPJGFMD
    struct UIMetaInfo {
        bool OKMCBOMPIML;
        bool BHHCEBPMJBP;
    };

    enum class InputMode__Enum : int32_t {
        None = 0x00000000,
        Normal = 0x00000001,
        TabMenu = 0x00000002,
        WheelMenu = 0x00000003,
        Disable = 0x00000004,
        Block = 0x00000005,
        SimpleMenu = 0x00000006,
        ScrollerMenu = 0x00000007,
    };

    enum class PCCursorMode__Enum : int32_t {
        Locked = -1,
        DontCare = 0x00000000,
        Normal = 0x000003e8,
    };

    struct __declspec(align(8)) BaseContext__Fields {
        struct PLGGMHHGNJK* config;
        int32_t uiType;
        int32_t queueType;
        int32_t canvasType;
        int32_t _loadState;
        int32_t _viewState;
        int32_t layerOrder;
        struct Queue_1_MoleMole_Notify_* _notifyQueue;
        struct Queue_1_MoleMole_Notify_* _eternalNotifyQueue;
        struct GameObject* _view_k__BackingField;
        struct MonoUIProxy* _monoProxy;
        struct UIMetaInfo _metaInfo_k__BackingField;
        struct List_1_UnityEngine_Events_UnityEventBase_* _bindedEvents;
        struct List_1_MoleMole_MonoEventTrigger_* _eventTriggers;
        struct List_1_UnityEngine_Coroutine_* _bindedCoroutines;
        struct Coroutine* _fadeOutCoroutine;
        struct Action_1_MoleMole_BaseContext_* onLoadFinish;
        struct Action* closeCallback;
        struct Action* releaseCallback;
        struct Action* fadeOutCallback;
        bool _setViewAsLast;
        bool _setViewAsFirst;
        struct List_1_MoleMole_BaseContextComponent_* _baseComponentList;
        struct List_1_MoleMole_BaseContextComponent_* _tickComponentList;
        struct List_1_MoleMole_BaseContextComponent_* _lateTickComponentList;
        struct Dictionary_2_System_Int32_List_1_MoleMole_BaseContextComponent_* _baseComponentNotifyRegister;
        struct Dictionary_2_System_Int32_List_1_MoleMole_BaseContextComponent_* _baseComponentPacketRegister;
        struct Dictionary_2_System_Int32_List_1_MoleMole_BaseContextComponent_* _baseComponentActionEventRegister;
        uint32_t _pageHandler;
        bool _isIndependentLoaded;
        bool _UIResolutionChanged_k__BackingField;
        bool _landFromBack_k__BackingField;
        bool _layoutVersionChanged_k__BackingField;
        struct HashSet_1_System_UInt16_* handlePacketSet;
        struct LPGAIFHDAHC* _jsonConfig;
        int32_t _stateID;
        struct IPKLEDPCMIN__Array* _inputEvents;
        bool _useCustomInputEvent;
        struct List_1_IPKLEDPCMIN_* _customeInputEvent;
        bool _enableJoypadVirtualCursor;
        struct Nullable_1_Boolean_ _forceEnableJoypadVirtualCursor;
        bool _handledInputEvents;
        int32_t _inputMode;
        uint32_t _keySettingID;
        struct List_1_HHOMOPLIOLJ_* _joypadControllerCache;
        bool _needResolveJoypadController;
        bool _useCommonTemplateConfig;
        bool _needResolveKeyMouseController;
        bool _needAutoHideContextJoypadIconOnBackend;
        struct Dictionary_2_System_Int32_UniRx_Tuple_3_* _storedJoypadIconStateIns;
        struct Dictionary_2_System_String_HHOMOPLIOLJ_* _name2JoypadController;
        int32_t _pcCursorMode;
        bool _updateJoypadUIModule;
        bool _contextClosed;
        struct List_1_MoleMole_BaseContext_JoypadUIModulesList_* _joypadUIModules;
        struct List_1_MoleMole_MonoJoypadUIModule_* _modulesToBeAdd;
        struct List_1_MoleMole_MonoJoypadUIModule_* _modulesToBeRemove;
        struct List_1_MoleMole_MonoJoypadUIModule_* _joypadUIModuleCache;
        struct List_1_MoleMole_MonoJoypadNavRegionBase_* _navRegionCache;
        bool _changeClimateLen;
        bool _showClimateLenEff;
        bool _immedialteClimateLenEff;
        struct Dictionary_2_MoleMole_MonoControllerIcon_Stack_1_System_Boolean_* _controllerIconWithState;
        struct List_1_MoleMole_MonoControllerIcon_* controllerIcons;
        struct MJNGIMLAOFN* _spriteLoadProxy;
    };

    //BLDKFDKIPLL__Fields
    struct BasePageContext__Fields {
        struct BaseContext__Fields _;
        struct List_1_BaseDialogContext_* dialogContextList;
        struct List_1_KFFFGJNHFBL_* subPageContextList;
        bool _forceLodOff;
        bool _autoClosePageOnBackEvent;
        bool _disableMainCamera;
        bool _pauseLevelTime;
        bool _asyncLoadRes;
        struct Coroutine* _cameraCoroutine;
        bool _joyFocusOnParentPage;
    };

    struct InLevelMapPageContext__Fields {
        struct BasePageContext__Fields _;
        struct GameObject* _mapGameObject;
        struct MonoLevelMapUI* _mapScript;
        struct MonoInLevelMapPage* _pageMono;
        struct MoleMole_RewardPreviewComponent* _rewardPreviewComponent;
        uint32_t _mapFogHandle;
        struct Action* _loadingCallback;
        struct Dictionary_2_System_UInt32_MoleMole_MonoMapMark_* _transPointMarks;
        struct Dictionary_2_System_Int32_Dictionary_2_System_UInt32_MoleMole_MonoMapMark_* _markType2markDic;
        struct Rect _mapViewRect;
        struct MonoMapMark* _localAvatarMark;
        struct Rect _markContainerViewport;
        struct MoleMole_InfoTextDialogContext* _infoTextDialog;
        int32_t _markLayer;
        uint32_t _markId;
        struct GeneralMarkData* _trackingMark;
        MoleMole_Config_MarkType__Enum _markType;
        bool _needTrack;
        struct List_1_MoleMole_MonoMapMark_* _nearMarks;
        struct MonoMapMark* _hintMark;
        struct Vector3 _customMarkWorldPos;
        struct String* _customMarkTitle;
        MoleMole_Config_MarkIconType__Enum _customMarktype;
        bool KHDDHMIGLMH;
        bool AGABBDCCGPJ;
        bool GBCMNPNHCBH;
        uint32_t _customMarkTrackMonsterID;
        uint32_t _customMarkTrackQuestID;
        MoleMole_CustomMarkTrackReasonType__Enum NHIIHLLCJAI;
        bool _isAdventureHandbookOpened;
        float _slideValue;
        struct MoleMole_ResinViewComponent* _resinComp;
        struct MoleMole_ZoomAudioComponent* _zoomAudioComp;
        struct Dictionary_2_MoleMole_MonoMapMark_UnityEngine_GameObject_* trackingIndictor;
        struct Coroutine* ELELLFBCPFM;
        bool _NJHAEHLFGNP_k__BackingField;
        bool JNBIIIHNPOL;
        float FMNNMKICFCN;
        struct Vector2 JIEJCHOKMCH;
        float EGDCGHPCIGD;
        float NNGIPKNIHHL;
        struct Vector2 MABOFOAAIDK;
        float OOOKLDFFEOK;
        bool DAMOBDBBBPD;
        struct Vector2 _currRectPos;
        struct Vector2 _currRectSize;
        struct Dictionary_2_System_UInt32_UnityEngine_GameObject_* _companionIndicators;
        struct List_1_System_UInt32_* EDDEMHGPOBD;
        struct GameObject* _playerIndicator;
        struct Vector2 _newPos;
        struct Dictionary_2_System_UInt32_UnityEngine_GameObject_* _questAreaMarkDic;
        struct GameObject* _lockBlueObj;
        bool _canTrans;
        uint32_t _unlockAreaID;
        struct GameObject* _lockRedObj;
        bool _showDisableLimitRegion;
        struct PointerEventData* _cursorPointer;
        struct List_1_UnityEngine_EventSystems_RaycastResult_* _raycastResults;
        struct GameObject* _currOverGameObject;
        bool _anyMarkUnderCursor;
        bool _resinOpened;
        MoleMole_Config_MapTagType__Enum _currTag;
        uint32_t _currShownID;
        uint32_t _currSelectedID;
        struct MoleMole_Config_MapTagDataConfig* _currSelectedConfig;
        struct List_1_MoleMole_Config_MapTagDataConfig_* _mapTagConfig;
        uint32_t _sceneToLoad;
        int32_t _currSelectIndex;
        struct MonoMapMark* _selectedDungeonMark;
        uint32_t BOSS_DUNGEON_ENTRY_ID;
        MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_MarkTipsContentType__Enum _markTipsContentType;
        struct List_1_MoleMole_BagItem_* _reward;
        struct List_1_MoleMole_Config_IdCountStrConfig_* _rewardPreviewList;
        float BCHEAHAGENA;
        uint32_t _dungeonEntryPointID;
        struct MoleMole_Config_DungeonEntry* _selectedDungeonEntry;
        MoleMole_InLevelMapPageContext_MoleMole_InLevelMapPageContext_DungeonEntryState__Enum _selectDungeonEntryState;
        struct Coroutine* _updateDungeonCooldownTipsCoroutine;
        struct MoleMole_ItemTipsDialogHelper _itemTipsHelper;
        struct Coroutine* _updateFarmFieldCoroutine;
        struct GameObject* _newMaxLevelGO;
        struct MoleMole_RewardPreviewComponent* _moonfinTrialRewardPreviewComponent;
        struct Coroutine* _updateReviveCooldownCoroutine;
        int32_t _selectedMapTagIndex;
        int32_t _selectedPanelTagIndex;
        struct MonoMapMark* _selectedCustomMark;
        int32_t _customMarkCount;
        struct MoleMole_Config_MarkIconType__Enum__Array* _customMarkIcons;
        struct Vector2 _currMapPos;
        struct Dictionary_2_System_UInt32_List_1_MoleMole_InLevelMapPageContext_BKKFEMNNBMG_* LOLNIIFFJON;
        int32_t MAPJENKCNNE;
    };

    struct InLevelMapPageContext {
        void* klass;
        MonitorData* monitor;
        InLevelMapPageContext__Fields fields;
    };

    struct BaseDialogContext__Fields {
        struct BaseContext__Fields _;
        bool attachToPage;
        bool _autoCloseDialogOnBackEvent;
        struct BLDKFDKIPLL* _pageContext_k__BackingField;
    };

    struct TalkDialogContext__Fields {
        struct BaseDialogContext__Fields _;
        bool _inCoopSelect;
        bool _inCoopTemperamentSelect;
        bool _coopSelectShow;
        int32_t _selectCoopIndex;
        struct List_1_MonoUIContainer_* _confidenceItemArray;
        struct DialogAction* _currDialogAction;
        struct DialogSelectAction* _currDialogSelectAction;
        struct MonoTalkDialog* _dialogMono;
        struct Config_ConfigDialogScheme* _currDialog;
        float _protectTime;
        bool _autoClick;
        struct String* CountDownProgressPrefab;
        uint32_t _handle;
        struct GameObject* _countDownGo;
        struct MonoTalkCountDownProgress* _countDownScript;
        struct List_1_SelectItemParam_* _selectParamList;
        struct Action* _updateGrpSelectBottom;
        struct List_1_System_UInt32_* _selectDialogIdList;
        bool EHOPIEOHBIJ;
        bool IEFCCCNLHFG;
        struct Action* _onFreeClick;
        float _interactableTime;
        float _autoTalkInteractableTime;
        struct Coroutine* _showClickTipCoroutine;
        bool _differentRole;
        struct Coroutine* _showSelectOptionsCoroutine;
        bool _inSelect;
        struct Coroutine* WaitDialogSelectCoroutine;
    };

    struct TalkDialogContext {
        struct TalkDialogContext__Class* klass;
        MonitorData* monitor;
        struct TalkDialogContext__Fields fields;
    };

    struct MonoTalkDialog__Fields {
        struct MonoUIProxy__Fields _;
        struct MonoGrpSelect* _selectGrp;
        struct MonoPrefabPlugin* _prefabPlugin;
        struct GameObject* _keyGameObject;
        struct MonoControlElement* monoControl;
        struct Animator* _clickAnimator;
        struct GameObject* _clickTip;
        struct Transform* _countDownTrans;
        struct GameObject* _conversationRoot;
        struct GameObject* _talkRoot;
        float _protectTime;
        float _clickTipAniTime;
        float _optionsDisplayDelay;
        float _waitDialogSelectTime;
        float _waitCoopSelectTime;
        struct MonoElementSwitch* _elementSwitch;
        bool _clickAniTimeAdd;
        struct MonoGrpConversation* _conversationGrp;
        struct MonoCoopPanel* _coopPanel;
    };

    struct MonoTalkDialog {
        struct MonoTalkDialog__Class* klass;
        MonitorData* monitor;
        struct MonoTalkDialog__Fields fields;
    };

    struct InLevelCutScenePageContext__Fields {
        struct BasePageContext__Fields _;
        struct MonoInLevelCutScenePage* _pageMono;
        struct TalkDialogContext* _talkDialog;
        struct Image* _backImg;
        struct GameObject* _loadingAnim;
        struct Animator* _textAnimator;
        bool _needFreeClick;
        bool _isChangingColor;
        struct Coroutine* _wait2ShowLoadingDialog;
        bool _talking;
        uint32_t _inteeID;
        struct MCNNFIPCOBO* MDJKLCLFDMJ;
        float _durationToHide;
        struct Vector2 _lastMousePos;
        float _lastMouseMoveTime;
        bool _firstUpdate;
        bool _needHideMouse;
    };

    struct InLevelCutScenePageContext {
        struct InLevelCutScenePageContext__Class* klass;
        MonitorData* monitor;
        struct InLevelCutScenePageContext__Fields fields;
    };

    struct Int32__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Int32__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
    };

    struct __declspec(align(8)) UIManager__Fields {
        struct LinkedList_1_MoleMole_BaseContext_* _inputContextList;
        struct HashSet_1_MoleMole_BaseContext_* _inputContextSet;
        PCCursorMode__Enum _currCursorMode;
        struct HashSet_1_MoleMole_BaseContext_* BCPDECEFFMF;
        struct UIPlatformConfig* platformConfig;
        uint32_t _curProfileHandle;
        void* _sceneCanvas;
        struct Camera* _uiCamera;
    };

    struct MoleMole_UIManager {
        struct UIManager__Class* klass;
        MonitorData* monitor;
        struct UIManager__Fields fields;
    };

    enum class CanBeModifiedBy__Enum : int32_t {
        None = 0x00000000,
        Owner = 0x00000001,
        OriginOwner = 0x00000002,
    };

    struct __declspec(align(8)) BDBOMOMOBNM__Fields {
        struct String* _attackTag;
        struct String* _attenuationTag;
        struct String* _attenuationGroup;
        struct ConfigAttackProperty* _attackProperty;
        struct ConfigHitPattern* _hitPattern;
        bool _canHitHead;
        struct JMEHFAFIGOB* _hitHeadPattern;
        bool _forceCameraShake;
        struct HIFJNLHKFEE* NADMPJNLGEC;
        struct EMKDPBDJPFA* HHIMIJDIPPE;
        CanBeModifiedBy__Enum FLCCOAEHOJH;
    };

    struct ConfigAttackInfo {
        struct BDBOMOMOBNM__Class* klass;
        MonitorData* monitor;
        struct BDBOMOMOBNM__Fields fields;
    };

    struct Rigidbody__Fields {
        struct Component_1__Fields _;
    };

    struct Rigidbody {
        struct Rigidbody__Class* klass;
        MonitorData* monitor;
        struct Rigidbody__Fields fields;
    };

    enum class VelocityForceType__Enum : int32_t {
        RetreatType = 0x00000000,
        RetreatAirType = 0x00000001,
        RushMoveType = 0x00000002,
        WindZoneType = 0x00000003,
        AirflowType = 0x00000004,
        RiseType = 0x00000005,
        SpeedupType = 0x00000006,
        AirflowAccType = 0x00000007,
        InertiaType = 0x00000008,
        FixedRushMoveType = 0x00000009,
        LightCoreTypeNormal = 0x0000000a,
        LightCoreTypeAccelerate = 0x0000000b,
        GorouZoneType = 0x0000000c,
        UGCDirectedForceType = 0x0000000d,
    };

    struct MoleMole_ItemModule {
        struct ItemModule__Class* klass;
        MonitorData* monitor;
        // struct ItemModule__Fields fields;
    };

    struct LevelSceneElementViewPlugin__VTable
    {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData get_listenEventValid;
        VirtualInvokeData set_listenEventValid;
        VirtualInvokeData ListenEvent;
        VirtualInvokeData CanHandleEvent;
        VirtualInvokeData get_metaTypeID;
        VirtualInvokeData get_isForceFullTick;
        VirtualInvokeData get_canBeTickedReadonly;
        VirtualInvokeData get_metaTypeID_1;
        VirtualInvokeData Init;
        VirtualInvokeData OnEntityReady;
        VirtualInvokeData Retarget;
        VirtualInvokeData ReInit;
        VirtualInvokeData PostReInit;
        VirtualInvokeData Clear;
        VirtualInvokeData ClearInThread;
        VirtualInvokeData OnEnable;
        VirtualInvokeData OnDisable;
        VirtualInvokeData Tick;
        VirtualInvokeData LateTick;
        VirtualInvokeData Destroy;
        VirtualInvokeData OnEvent;
        VirtualInvokeData OnRemoteEvtBeingHit;
        VirtualInvokeData OnEventResolved;
        VirtualInvokeData ListenEvent_1;
        VirtualInvokeData GetEntity;
    };

    struct LevelSceneElementViewPlugin__Class
    {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct LevelSceneElementViewPlugin__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct LevelSceneElementViewPlugin__VTable vtable;
    };

    struct LevelSceneElementViewPlugin__Fields
    {
        struct BaseComponentPlugin__Fields _;
        bool _triggerElementView;
        float _keepElementViewTime;
        struct ElementView* _elementViewSetting;
        float _transition;
        struct Action* onStartElementView;
        struct Action* onFinishElementView;
    };

    struct LevelSceneElementViewPlugin
    {
        struct LevelSceneElementViewPlugin__Class* klass;
        MonitorData* monitor;
        struct LevelSceneElementViewPlugin__Fields fields;
    };

    struct Nullable_1_Single_ {
        float value;
        bool has_value;
    };

    struct CameraEntity__Fields {
        struct BaseEntity__Fields _;
        bool _KHMCIEEKOKE_k__BackingField;
        struct Camera* _AOBHHGONMME_k__BackingField;
        struct MoleMole_VCStackCamera* _vcStackCamera;
        struct MoleMole_VCCameraCharacterAmbientSensors* _vcSensors;
        bool _KKCBBGNJFOA_k__BackingField;
        float _MFBEFHCONNJ_k__BackingField;
        float _AEMIJJPOBLN_k__BackingField;
        bool _JFJEPKEONHO_k__BackingField;
        float _CKDMDCFIDBL_k__BackingField;
        struct Vector3d_1 _KCGNBELKOFL_k__BackingField;
        void* /*HNGOGENCDGD__Enum*/ _GKAKGCPIPIK_k__BackingField;
    };

    struct CameraEntity {
        struct CameraEntity__Class* klass;
        MonitorData* monitor;
        struct CameraEntity__Fields fields;
    };

    struct __declspec(align(8)) NLHGPLIGNNJ__Fields {
        EventID__Enum eventID;
        uint32_t targetID;
        bool canBeHandledImmediately;
        bool canBeHandledByLogic;
        bool canBeHandledByVisual;
        bool canBeHandledByLogicResolved;
        bool canBeHandledByDispatcher;
        bool canBeHandledOnlyByListeners;
        bool canBeHandledIfDie;
        bool fromEventCache;
        EventRemoteState__Enum remoteState;
        ForwardType__Enum forwardType;
        uint32_t fromPeerID;
    };

    struct BaseEvent {
        struct NLHGPLIGNNJ__Class* klass;
        MonitorData* monitor;
        struct NLHGPLIGNNJ__Fields fields;
    };

    struct EvtCrash__Fields {
        struct BaseEvent__Fields _;
        float velChange;
        float maxHp;
        struct Vector3 hitPos;
    };

    struct EvtCrash {
        struct EvtCrash__Class* klass;
        MonitorData* monitor;
        struct EvtCrash__Fields fields;
    };

    struct MoveSyncTask {
        struct Vector3 position;
        struct Vector3 velocity;
        struct Vector3 forward;
        struct Vector3 up;
        struct Quaternion rotation;
        int32_t motion;
        int32_t paramNumber;
        struct Vector3 param0;
        struct Vector3 param1;
        struct Vector3 param2;
        struct Vector3 param3;
        uint32_t time;
        uint32_t reliableSeq;
        uint32_t clientSequenceId;
        uint32_t subSequenceId;
        bool reliable;
        bool isFake;
        struct Vector3 refPosition;
        uint32_t refEntityId;
        uint32_t refEntityTimestamp;
        bool hasValue;
        struct Vector3 positionRS;
        struct Vector3 positionRSLocal;
        uint32_t randomDelay;
        int32_t frameCountWhenAddTask;
    };

    struct BaseMoveSyncPlugin__Fields {
        struct BaseComponentPlugin__Fields _;
        struct JEACJCEKBMO__Array* JFHIPAJNCEH;
        struct MoveSyncTask moveSyncTask;
        int32_t EBAFCLPDNOA;
        struct PAGLNCJFJAB* EGOGHHCEKBI;
        uint32_t BMEKGDMGLDM;
        float BPNLDBMLCPG;
        int32_t IMGAJKMBICM;
        int32_t JFNJPLBNEAH;
        uint64_t LDHCFEHMENK;
        struct MoveSyncTask PKJLBFAGDPG;
        float KHDFGOBLNOH;
        bool BAHIDGDKDPG;
        bool MPNMLBJNIJK;
        float BPNMMCBBPDO;
        uint32_t DANEEGOIAOE;
        struct HBGKJGFOBDG* HHAPKOKPBPN;
        bool KCODNABDGKC;
        uint64_t PHBBAMKNKEH;
        uint32_t JEKLOEMBBJB;
        struct MoveSyncTask GPOABHBBEGL;
    };

    struct BaseMoveSyncPlugin {
        struct BaseMoveSyncPlugin__Class* klass;
        MonitorData* monitor;
        struct BaseMoveSyncPlugin__Fields fields;
    };

    struct __declspec(align(8)) ADOCDLJKPGF__Fields {
        struct Dictionary_2_UniRx_Tuple_2_Dictionary_2_System_UInt32_MoleMole_IndexHandleObjectList_1_* PKPGAJELFJP;
        struct Dictionary_2_System_UInt32_MoleMole_IndexHandleObjectList_1__2* EPNNKHDPMKN;
        struct Dictionary_2_System_UInt32_Dictionary_2_System_Type_ADOCDLJKPGF_NCKPKBOOPAE_* NHLMDJCPBOI;
        struct List_1_NLHGPLIGNNJ_* OCCMKONNAFF;
        struct List_1_NLHGPLIGNNJ_* ODMMGNLPPKO;
        struct List_1_NLHGPLIGNNJ_* FMJOCJEEDNA;
        struct Dictionary_2_System_Type_MoleMole_IndexHandleObjectList_1_* BGCNGICCMNG;
        bool IKIHCFFFACC;
        struct List_1_UniRx_Tuple_5__1* AOENJPJCHCP;
        int32_t AANDAKJMONI;
        bool GEPOJPNFMKO;
    };

    struct MoleMole_EventManager {
        struct ADOCDLJKPGF__Class* klass;
        MonitorData* monitor;
        struct ADOCDLJKPGF__Fields fields;
    };

    struct ActorAbilityPlugin__Fields {
        struct BaseComponentPlugin__Fields _;
        struct Action_3_BaseEntity_Config_AddGlobalValue_ActorAbility_* _addGlobalValueHandlerClosureDelegate;
        struct Action_3_BaseEntity_Config_SetGlobalValue_ActorAbility_* _setGlobalValueHandlerClosureDelegate;
        struct Action_3_BaseEntity_Config_MultiplyGlobalValue_ActorAbility_* _multiplyGlobalValueHandlerClosureDelegate;
        struct Action_4_BaseEntity_Config_SetTargetNumToGlobalValue_ActorAbility_Single_* BFCGFMBGIHB;
        struct Action_4_BaseEntity_String_Single_GJKAGOLAHKK_* OJKOMJEBCLM;
        struct List_1_MonoEffectProxyHandle_* _effectProxyListCache;
        struct List_1_MonoEffectProxyHandle_* _effectProxyListCacheForChangFollowDampTime;
        struct List_1_UnityEngine_Vector3_* _pushedPosList;
        struct LCAbility* _owner;
        struct List_1_ActorAbility_* _appliedAbilities;
        struct Dictionary_2_System_UInt32_System_Int32_* _appliedAbilitiesIndex;
        uint32_t nextValidAbilityID;
        struct List_1_ActorModifier_* _appliedModifiers;
        struct List_1_ActorModifier_* _deadModifiers;
        struct List_1_ActorModifier_* _appliedServerBuffModifiers;
        struct List_1_ActorModifier_* _allAppliedModifiers;
        bool _isTicking;
        struct List_1_ActorAbility_* _tickAbilities;
        struct List_1_ActorAbility_* _addTickAbilities;
        struct List_1_ActorAbility_* _removeTickAbilities;
        struct List_1_ActorModifier_* _tickModifiers;
        struct List_1_ActorModifier_* _addTickModifiers;
        struct List_1_ActorModifier_* _removeTickModifiers;
        struct Dictionary_2_EncryptedString_DynamicActorValue_1_* _dynamicFloatMap;
        bool _isKilled;
        struct LCAbilityElement* lcAbilityElement;
        struct LCAbilityState* lcAbilityState;
        struct TokenManager* _tokenMgr;
        struct Func_3_Single_Object_Boolean_* _hanlderModifierThinkTimerUp;
        struct List_1_System_Nullable_1__3* _modifierThinkTimers;
        struct HashSet_1_TimerReceiver_* _modifierThinkTimersAffectedByTimeScale;
        struct HashSet_1_TimerReceiver_* _modifierThinkTimersAffectedByAlive;
        struct Action_1_EvtEntityTimeScaleChange_* _onOwnerTimeScaleChangedCache;
        struct Action_1_EvtEntityAliveChange_* _onOwnerAliveChangedCache;
        bool _isOnEventing;
        struct Dictionary_2_System_Int32_List_1_BaseAbilityMixin_* _onEventMixins;
        struct List_1_BaseAbilityMixin_* _addOnEventMixins;
        struct List_1_BaseAbilityMixin_* _removeOnEventMixins;
        bool _isOnEventRemoting;
        struct Dictionary_2_System_Int32_List_1_BaseAbilityMixin_* _onEventRemoteMixins;
        struct List_1_BaseAbilityMixin_* _addOnEventRemoteMixins;
        struct List_1_BaseAbilityMixin_* _removeOnEventRemoteMixins;
        bool _isOnEventResolveing;
        struct Dictionary_2_System_Int32_List_1_BaseAbilityMixin_* _onEventResolvedMixins;
        struct List_1_BaseAbilityMixin_* _addOnEventResolvedMixins;
        struct List_1_BaseAbilityMixin_* _removeOnEventResolvedMixins;
        bool _isListenEventing;
        struct Dictionary_2_System_Int32_List_1_BaseAbilityMixin_* _listenEventMixins;
        struct List_1_BaseAbilityMixin_* _addListenEventMixins;
        struct List_1_BaseAbilityMixin_* _removeListenEventMixins;
        int32_t ECLCGLCLPPD;
        bool IsImmuneDebuff;
        bool _isDuringInitAbility_k__BackingField;
        bool _isDuringChangeAbility_k__BackingField;
        struct Action_1_EvtEntityReadyPost_* _handleServerBuffChangedOnEntityReady;
        struct Dictionary_2_System_UInt32_AvatarDataItem_AvatarDataItem_ServerBuffInfo_* _addSBuffsBeforeEntityReady;
        struct Dictionary_2_System_UInt32_AvatarDataItem_AvatarDataItem_ServerBuffInfo_* _rmvSBuffsBeforeEntityReady;
        struct SpriteLoadProxy* _spriteLoadProxy;
        struct Dictionary_2_System_UInt32_BaseAttachContainer_* _abilityAttachContainers;
        struct Dictionary_2_System_UInt32_BaseAttachContainer_* _modifierAttachContainers;
        struct ClosureList* _onEntityReadyClosureList;
        struct Action_1_EvtEntityReadyPost_* _callOnEntityReadyClosure;
    };

    struct ActorAbilityPlugin {
        struct ActorAbilityPlugin__Class* klass;
        MonitorData* monitor;
        struct ActorAbilityPlugin__Fields fields;
    };

    enum class Miscs_ChangeAvatarFailType__Enum : int32_t {
        NONE = 0x00000000,
        FAIL_AIM = 0x00000001,
        FAIL_CLIMB = 0x00000002,
        FAIL_FLY = 0x00000003,
        FAIL_JUMP = 0x00000004,
        FAIL_LADDER = 0x00000005,
        FAIL_SWIM = 0x00000006,
        FAIL_IN_PROCESS = 0x00000007,
        FAIL_LEVEL_FORBIDDEN = 0x00000008,
        FAIL_TARGETAVATAR = 0x00000009,
        FAIL_PERFORM = 0x0000000a,
        FAIL_DEAD = 0x0000000b,
        FAIL_COOLDOWN = 0x0000000c,
    };

    struct __declspec(align(8)) GMNHONOINDB__Fields {
        struct Dictionary_2_System_UInt32_Dictionary_2_System_Int32_List_1_CFKBGDNLDGP_* MFEPPBMCAGP;
    };

    enum class MoleMole_Config_JsonClimateType__Enum : int32_t {
        Normal = 0x00000000,
        Cold = 0x00000001,
        Hot = 0x00000002,
        ColdMonster = 0x00000003,
        HotMonster = 0x00000004,
        SeaMist = 0x00000005,
        HeroCourse = 0x00000006,
        SeaMistSurrounding = 0x00000007,
        TatariRegion = 0x00000008,
        TransClimate = 0x00000009,
        SeiraiStorm = 0x0000000a,
        TsurumiMist = 0x0000000b,
        TsurumiThunder = 0x0000000c,
        TsurumiRegionalMist = 0x0000000d,
        Count = 0x0000000e,
    };

    struct __declspec(align(8)) DataItem__Fields {
        uint32_t _entityId_k__BackingField;
        struct Dictionary_2_MoleMole_SafeUInt32_MoleMole_SafeDouble_* _cacheNormalPropValueDic;
        struct Dictionary_2_MoleMole_SafeUInt32_MoleMole_SafeFloat_* _cacheFightPropValueDic;
        bool isToBeRemoved;
        bool _unCacheEntity;
        MoleMole_Config_JsonClimateType__Enum climateType;
        uint32_t climateAreaID;
    };

    struct DataItem {
        struct DataItem__Class* klass;
        MonitorData* monitor;
        struct DataItem__Fields fields;
    };

    struct BEKFICFOHKL__Fields {
        struct DataItem__Fields _;
        uint32_t accountType;
        uint32_t channelID;
        bool isGuest;
        struct String* accountUid;
        struct String* accountToken;
        uint32_t userId;
        uint32_t regionId;
        struct String* deviceUUID;
        struct String* onlineID;
        struct String* psnID;
        uint32_t nameCardID;
        struct String* token;
        struct String* nickName;
        uint64_t chooseAvatarGuid;
        uint64_t lastChangeAvatarTime;
        uint32_t level;
        uint32_t exp;
        uint32_t maxExp;
        uint32_t fullCost;
        bool isFirstLogin;
        bool isFirstShare;
        uint32_t cookGrade;
        struct Dictionary_2_System_UInt32_CJJDPGJPGJB_* cookRecipeDic;
        struct List_1_System_UInt32_* compoundList;
        struct Dictionary_2_System_UInt32_HBAOILFEMEH_* compoundItemDic;
        struct List_1_System_UInt32_* rewardLevelList;
        struct Dictionary_2_System_UInt32_System_Int32_* newCombineDic;
        struct Dictionary_2_System_UInt32_System_Int32_* newForgeDic;
        uint32_t currForgePoint;
        struct HashSet_1_System_UInt32_* unlockedCombineSet;
        struct HashSet_1_System_UInt32_* unlockedForgetSet;
        //struct IIJPJKLFKBK headPortrait;
        //struct String* signature;
        //struct isShowAvatar birthday;
        //bool IPDELLPNFLE;
        //struct List_1_System_UInt32_* showAvatarIdList;
        //struct List_1_System_UInt32_* showNameCardIdList;
        //struct List_1_System_UInt32_* ownedFlyCloakList;
        //struct List_1_System_UInt32_* ownedCostumeList;
        //uint32_t curAvatarEntityID;
    };

    struct AccountDataItem {
        struct AccountDataItem__Class* klass;
        MonitorData* monitor;
        struct BEKFICFOHKL__Fields fields;
    };

    struct NEOGDEDNDHF__Fields {
        struct GMNHONOINDB__Fields _;
        struct AccountDataItem* _accountData_k__BackingField;
        struct HBFICKPEILE* openState;
        uint32_t curWorldType;
        uint32_t curSceneID;
        struct OGNHDKJOONG* _curSceneConfig;
        bool isSereverLevelPaused;
        uint32_t extraAbilityId;
        bool extraAbilityEnable;
        uint64_t extraAbilityUseTime;
        float AJMFBGNGPIB;
        float KJKAPGLEELE;
        struct List_1_UniRx_Tuple_3_* INANHBPCBLC;
        bool MAOHENNPOMB;
        bool HEJLGFNHKND;
        bool NABCGFBLKDJ;
        bool PNGMLKJFKND;
        bool MNMODNDPIDD;
        uint32_t OODBAMHAGPO;
        uint32_t JPKIAEFDHMD;
        bool NFMOCKLFAOF;
        float JJLIHANGKEO;
        struct Dictionary_2_System_UInt64_System_UInt32_* ICPIOBFBPGA;
        struct LGPKIADMOBE_System_UInt64_CJFLLIKJGLF_* BDBFEGIMOFI;
        struct DPHDLLFCIBC* HDOGLGNGMAP;
        struct PHHEDBDLADE* ANDABFFFNHE;
        struct Action_1_Single_* KGABFCPEBDG;
        struct Dictionary_2_System_UInt32_System_UInt32_* EPNCJKKPNIN;
        struct List_1_System_UInt64_* IDPDPDAENDP;
        bool HJOJBIBHGEC;
        struct List_1_JBONEPGMKAD_* ODDFKLCINLC;
        struct Coroutine* FCJOEAPBMHB;
        Miscs_ChangeAvatarFailType__Enum FDFCHGCAIPL;
        uint32_t MFKCKBGCADE;
        struct String* DMMKLMDFDLE;
        struct String* JKFKIOAJPKF;
        struct Dictionary_2_System_UInt32_System_UInt32_* FMMDIGIIBJB;
        float NDFMECJGCKK;
        float BHAMGAPDFEH;
        uint32_t AFIIDKIKKMB;
        struct List_1_System_UInt32_* DNKMPLJPOHG;
        uint32_t MAPMNIDOJCG;
        bool MIMGJGCADKB;
        uint32_t LCMMMGHFEGG;
        uint32_t DCGJMGBIDLD;
        uint32_t GGJMEBPNECC;
        uint32_t PIJHFCGJBJM;
        struct CAIMHKHHLHK_LJBGLAADLNC_* FFMOHPPEKLN;
        struct CAIMHKHHLHK_LJBGLAADLNC_* BLPNAPNOPFN;
        uint64_t ONAPAACFOBM;
        struct JIBKJBJNFED* LGADGGJMODA;
    };

    struct MoleMole_PlayerModule {
        struct PlayerModule__Class* klass;
        MonitorData* monitor;
        struct NEOGDEDNDHF__Fields fields;
    };

    enum class MapManager_FEDPCJIHAJJ__Enum : int32_t {
        None = 0x00000000,
        Morning = 0x00000001,
        Day = 0x00000002,
        Afternoon = 0x00000003,
        Night = 0x00000004,
        BadWeather = 0x00000005,
    };

    struct Nullable_1_MoleMole_AsyncJob_ {
        struct AsyncJob value;
        bool has_value;
    };

    struct __declspec(align(8)) MHCEDJLGNMG__Fields {
        struct String* _curLimitRegionName;
        bool _isCurActivityLimitRegion;
        bool _isCurHomeworldLimitRegion;
        struct Coroutine* _curDestroyLimitRegionCoroutine;
        struct Dictionary_2_System_String_MKKACPLIBDI_* _polygonLimitRegions;
        struct MKKACPLIBDI* _curPolygonLimitRegion;
        struct String* _curPolygonLimitRegionName;
        bool GJKFDGHHMFA;
        float _limitRegionDistance;
        struct Vector3 _limitRegionDirection;
        struct GameObject* mapObj;
        struct MonoLevelMapUI* monoLevelMapUI;
        uint32_t _mapContainerHandle;
        uint32_t playerSceneID;
        uint32_t mapSceneID;
        struct SceneScriptData* _sceneDataInMap;
        struct MapScriptData* mapData;
        struct String* _currMapPrefabPath;
        struct Nullable_1_MoleMole_AsyncJob_ IPADPFPPDJI;
        bool _forceCurrentScene;
        uint32_t _mapSceneIDSelected;
        bool DebugNewmap;
        struct String* currMapString;
        struct RectTransform* currParent;
        struct GameObject* mapGameObjectInst;
        uint32_t _mapImageHandle;
        struct MonoLevelMap* levelMap;
        float mainPageCheckDistance;
        MapManager_FEDPCJIHAJJ__Enum _currState;
        bool _hasSignal;
        struct Vector3 _signalPos;
        float _distanceThreshold;
        uint32_t _id;
        bool CHKBLNNDFDH;
        struct Dictionary_2_System_UInt32_List_1_CCHDCNEBLGP_* KKDHHBEFNNF;
        struct List_1_System_String_* EENBABIJFKD;
        struct List_1_System_String_* FDFHCABDDFE;
        bool NMJJKJPPIGC;
    };

    struct MoleMole_MapManager {
        struct MapManager__Class* klass;
        MonitorData* monitor;
        struct MHCEDJLGNMG__Fields fields;
    };

    struct ANPOFFEGJHG__Fields {
        struct BaseEntity__Fields _;
        uint32_t groupId;
        uint32_t markFlag;
        uint32_t propOwnerRuntimeID;
        bool hasSyncCreate;
        bool _lifeByOwnerLife;
        bool _registedLifeToOwner;
        uint32_t _ownerRuntimeID;
        struct Action* _ownerReadyAction;
        uint32_t _originOwnerRuntimeID;
        struct List_1_System_UInt32_* _childrenRuntimeIds;
        struct List_1_System_String_* _tags;
        /*
        struct ANPOFFEGJHG_NGHFEJMFKFL EPLELPAMJBC;
        bool KCCHJICIHOH;
        struct CDIKPMFDALH* AALEGLLIIMC;
        struct LIILPNJKBJI* CFNHGPAJECO;
        bool NKJDGPLLBBD;
        */
    };

    struct GadgetEntity {
        struct GadgetEntity__Class* klass;
        MonitorData* monitor;
        struct ANPOFFEGJHG__Fields fields;
    };

    struct BaseComponent__Array {
        struct BaseComponent__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct BaseComponent* vector[32];
    };

    struct LCChestPlugin__Class {
        Il2CppClass_0 _0;
    };

    struct BaseComponent__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct BaseComponent__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        // struct BaseComponent__VTable vtable;
    };


    struct BaseComponent {
        struct BaseComponent__Class* klass;
        MonitorData* monitor;
        struct BaseComponent__Fields fields;
    };

    struct __declspec(align(8)) List_1_MoleMole_BaseComponent___Fields {
        struct BaseComponent__Array* _items;
        int32_t _size;
        int32_t _version;
    };

    struct List_1_MoleMole_BaseComponent_ {
        struct List_1_MoleMole_BaseComponent___Class* klass;
        MonitorData* monitor;
        struct List_1_MoleMole_BaseComponent___Fields fields;
    };

    enum class HOILKKLDNMA_LFAKNILHEEN__Enum : int32_t {
        None = 0x00000000,
        TrifleItem = 0x0000000c,
        GatherGadget = 0x0000000d,
        Worktop = 0x0000000e,
        ClientGadget = 0x0000000f,
        Weather = 0x00000011,
        AbilityGadget = 0x00000012,
        StatueGadget = 0x00000013,
        BossChest = 0x00000014,
        BlossomChest = 0x00000029,
        MpPlayReward = 0x0000002a,
        GeneralReward = 0x0000002b,
        OfferingInfo = 0x0000002c,
        FoundationInfo = 0x0000002d,
        VehicleInfo = 0x0000002e,
        ShellInfo = 0x0000002f,
        ScreenInfo = 0x00000030,
        FishPoolInfo = 0x0000003b,
        CustomGadgetTreeInfo = 0x0000003c,
        RoguelikeGadgetInfo = 0x0000003d,
    };

    struct WeeklyBossResinDiscountInfoStruct {
        uint32_t discountNum;
        uint32_t discountNumLimit;
        uint32_t resinCost;
        uint32_t originalResinCost;
    };


    struct GadgetDataItem_CBGKCHACFPE {
        uint32_t resinCost;
        uint32_t configId;
        uint32_t lifeTime;
        uint32_t blossomRefreshType;
        uint32_t blossomRefreshId;
        struct List_1_System_UInt32_* authorisedUIDList;
        struct List_1_System_UInt32_* openableUID;
        HOILKKLDNMA_LFAKNILHEEN__Enum type;
        struct WeeklyBossResinDiscountInfoStruct weeklyBossResinDiscountInfo;
    };

    struct Nullable_1_MoleMole_GadgetDataItem_CBGKCHACFPE_ {
        struct GadgetDataItem_CBGKCHACFPE value;
        bool has_value;
    };

    enum class GadgetState__Enum : int32_t {
        Default = 0x00000000,
        GatherDrop = 0x00000001,
        ChestLocked = 0x00000065,
        ChestOpened = 0x00000066,
        ChestTrap = 0x00000067,
        ChestBramble = 0x00000068,
        ChestFrozen = 0x00000069,
        ChestRock = 0x0000006a,
        GearStart = 0x000000c9,
        GearStop = 0x000000ca,
        GearAction1 = 0x000000cb,
        GearAction2 = 0x000000cc,
        CrystalResonate1 = 0x0000012d,
        CrystalResonate2 = 0x0000012e,
        CrystalExplode = 0x0000012f,
        CrystalDrain = 0x00000130,
        StatueActive = 0x00000191,
        Action01 = 0x00000385,
        Action02 = 0x00000386,
        Action03 = 0x00000387,
    };

    enum class AGGAOKGNDPF__Enum : int32_t {
        GadgetBornNone = 0x00000000,
        GadgetBornInAir = 0x00000001,
        GadgetBornPlayer = 0x00000002,
        GadgetBornMonsterHit = 0x00000003,
        GadgetBornMonsterDie = 0x00000004,
        GadgetBornGadget = 0x00000005,
        GadgetBornGround = 0x00000006
    };

    struct __declspec(align(8)) AALJCABGFEP__Fields {
        uint32_t _entityId_k__BackingField;
        struct Dictionary_2_KFEENBPGJJA_JMOFLAAALOE_* _cacheNormalPropValueDic;
        struct Dictionary_2_KFEENBPGJJA_IPEPPEAIJEC_* _cacheFightPropValueDic;
        bool _isToBeRemoved;
        bool _unCacheEntity;
        int32_t climateType;
        uint32_t climateAreaID;
    };

    struct LCIKPOFEIAP_IOJMGCFMHAN {
        struct DNPMEDDBDLJ* GLJPNCEBHIO;
    };

    struct Nullable_1_LCIKPOFEIAP_IOJMGCFMHAN_ {
        struct LCIKPOFEIAP_IOJMGCFMHAN value;
        bool has_value;
    };

    struct LCIKPOFEIAP__Fields {
        struct AALJCABGFEP__Fields _;
        uint32_t configId;
        uint32_t mapInstId;
        uint32_t groupId;
        uint32_t markFlag;
        AGGAOKGNDPF__Enum bornType;
        struct DFMGHHMLIJK* item;
        uint32_t gatherItemId;
        bool isForbitGuest;
        bool isShowCutscene;
        uint32_t gadgetState;
        bool isEnableInteract;
        uint32_t authorityPeerId;
        struct LHANLGFNKOH* platformInfo;
        uint32_t interactId;
        bool isOpenedStatue;
        struct NKLKOKAKOJB* entityClientData;
        uint32_t mpPlayId;
        uint32_t draftId;
        uint32_t chainID;
        struct List_1_System_UInt32_* optionList;
        struct List_1_System_UInt32_* interactUids;
        struct Nullable_1_MoleMole_GadgetDataItem_CBGKCHACFPE_ _openData;
        struct Nullable_1_LCIKPOFEIAP_IOJMGCFMHAN_ _foundationData;
        uint32_t liveId;
        uint32_t vodInteeId;
        struct UInt64__Array* _avatarsInVehicle;
        uint32_t ownerUid;
        uint32_t VEHICLE_SEAT_MAX;
        float cur_stamina;
        struct BIMFGAMJHFJ* fishPoolInfo;
        uint32_t roguelikeCellId;
        uint32_t roguelikeCellType;
        uint32_t roguelikeCellState;
    };

    struct GadgetDataItem {
        struct GadgetDataItem__Class* klass;
        MonitorData* monitor;
        struct LCIKPOFEIAP__Fields fields;
    };

    struct OMBJBEDFEJP__Fields {
        struct LCBase__Fields _;
        struct ConfigGadgetMisc* config;
        GadgetState__Enum curGadgetState;
        struct GadgetDataItem* _dataItem;
        struct LCPose* _lcPos;
        struct LCChestPlugin* _chestPlugin;
    };

    struct LCGadgetMisc {
        struct LCGadgetMisc__Class* klass;
        MonitorData* monitor;
        struct OMBJBEDFEJP__Fields fields;
    };

    struct __declspec(align(8)) ConfigChest__Fields {
        bool _bornLockedByAbility;
        struct String* _openEffect;
        bool _triggerOpenChestVo;
    };

    struct ConfigChest {
        struct ConfigChest__Class* klass;
        MonitorData* monitor;
        struct ConfigChest__Fields fields;
    };

    struct LCChestPlugin__Fields {
        struct BaseComponentPlugin__Fields _;
        struct ConfigChest* config;
        struct LCGadgetMisc* _owner;
        bool _marked;
        bool _isLockByAbility;
        struct LevelGadget* _levelGadget;
        struct Nullable_1_MoleMole_GadgetDataItem_CBGKCHACFPE_ _bossChestData;
        struct EntityTimerReceiver* _inteeActiveTimer;
    };

    struct LCChestPlugin {
        struct INNLBCONIIK__Class* klass;
        MonitorData* monitor;
        struct LCChestPlugin__Fields fields;
    };

    struct __declspec(align(8)) FKHDAEKGMKC__Fields
    {
        struct ScenePropEffectConfigs* _scenePropEffectConfigs;
        uint32_t _scenePropEffectConfigsHandle;
        struct SceneChairConfigs* _sceneChairConfigs;
        uint32_t _sceneChairConfigsHandle;
        struct SceneBushConfigs* _sceneBushConfigs;
        uint32_t _sceneBushConfigsHandle;
        struct SceneTreeConfigs* _sceneTreeConfigs;
        uint32_t _sceneTreeConfigsHandle;
        struct SceneStoneTintConfigs* IJAJFDDPIBF;
        uint32_t MPGIOKCAEDG;
        struct Dictionary_2_System_Int32_IIJMGCIOIAP_* _treeBushCollection;
        struct List_1_NAKCOANCOHK_* _treeBushList;
        struct Dictionary_2_System_Int32_UnityEngine_Vector3_* _treeBushId2Pos;
        struct Vector3 _rangeQueryLen;
        struct Dictionary_2_System_Int32_NAKCOANCOHK_* _scenePropDict;
        struct Dictionary_2_System_Int32_ECGLPBEEEAA_* _treeTypeDict;
        struct List_1_MoleMole_MonoEnviroLight_* _pointLights;
        struct List_1_MoleMole_MonoEnviroCityLight_* _cityLights;
        struct Vector3 _lastSectorPos;
        struct FKHDAEKGMKC_DEGEMNHILIP__Array* _treeLeafInfos;
        int32_t _treeLeafNum;
        struct MaterialPropertyBlock* _mpb;
        struct Camera* _mainCam;
        struct List_1_UnityEngine_Material_* _leafDitherMaterials;
        struct Dictionary_2_System_Int32_UnityEngine_Vector3__1* _shakeAnims;
        struct List_1_NAKCOANCOHK_* _playingScenePropShakes;
        struct List_1_JNFKAAAPLGE_* _chairs;
        struct GameObject* iceBlockRoot;
        struct GameObject* _surfaceMeshObjectRoot;
        struct GameObject* _tileMeshObjectRoot;
    };

    struct MoleMole_ScenePropManager
    {
        struct FKHDAEKGMKC__Class* klass;
        MonitorData* monitor;
        struct FKHDAEKGMKC__Fields fields;
    };


    enum class ScenePropType__Enum : int32_t {
        None = 0x00000000,
        Tree = 0x00000001,
        Bush = 0x00000002,
        Stone = 0x00000003,
        TreeLeaf = 0x00000004,
        EnviroLight = 0x00000005,
        RoomLight = 0x00000006,
        Chair = 0x00000007,
        EnviroCityLight = 0x00000008,
        Count = 0x00000009,
    };


    struct Bounds {
        struct Vector3 m_Center;
        struct Vector3 m_Extents;
    };
    struct __declspec(align(8)) BaseScenePropObject__Fields {
        uint32_t patternNameHash;
        uint32_t effectPatternNameHash;
        struct GameObject* mainObj;
        int32_t instanceId;
        ScenePropType__Enum sceneType;
    };

    struct BaseCombatScenePropObject__Fields {
        struct BaseScenePropObject__Fields _;
        struct Bounds realBounds;
        uint32_t entityId;
        struct Vector3__Array* _anims;
        struct Vector3 originalPos;
        float _playTime;
        bool _isFinish;
        bool _die;
    };

    struct JDJGACCAFAA__Fields
    {
        struct BaseCombatScenePropObject__Fields _;
        struct SceneTreeConfig* _config;
        uint64_t _lastTreeDropTimeStamp;
        uint64_t _lastHitEffectTimeStamp;
    };

    struct SceneTreeObject__Class
    { };

    struct SceneTreeObject
    {
        struct JDJGACCAFAA__Class* klass;
        MonitorData* monitor;
        struct JDJGACCAFAA__Fields fields;
    };

    struct __declspec(align(8)) ScenePropBaseConfig__Fields {
        struct String* scenePropPatternName;
    };

    struct ScenePropCombatBaseConfig__Fields {
        struct ScenePropBaseConfig__Fields _;
        struct Bounds triggerBounds;
        float shakeScale;
    };

    struct SceneTreeConfig__Fields {
        struct ScenePropCombatBaseConfig__Fields _;
        uint32_t configId;
        bool canDropItem;
        struct Vector3 dropOffsetPos;
        struct String* hitEffectName;
        uint64_t hitEffectCooldown;
    };

    struct SceneTreeConfig {
        struct SceneTreeConfig__Class* klass;
        MonitorData* monitor;
        struct SceneTreeConfig__Fields fields;
    };

    enum class MoleMole_Config_TreeType__Enum : int32_t
    {
        TREE_TYPE_BIRCH = 0x00000001,
        TREE_TYPE_MAPLE = 0x00000002,
        TREE_TYPE_PINE = 0x00000003,
        TREE_TYPE_POPULUS_EUPHRATICA = 0x00000004,
        TREE_TYPE_BAMBOO = 0x00000005,
        TREE_TYPE_ENERGY_WOOD = 0x00000006,
        TREE_TYPE_CYPRESS = 0x00000007,
        TREE_TYPE_FIRTREE = 0x00000008,
        TREE_TYPE_CERASUS = 0x00000009,
        TREE_TYPE_ACER = 0x0000000a,
        TREE_TYPE_CRYPTOMERIA = 0x0000000b,
        TREE_TYPE_OTOGI = 0x0000000c,
    };

    struct Tuple_4_MoleMole_ActorModifier_System_Single_MoleMole_IElementDurability_System_Single_ {
        struct ActorModifier* item1;
        float item2;
        struct IElementDurability* item3;
        float item4;
    };

    struct Tuple_4_MoleMole_ActorModifier_System_Single_MoleMole_IElementDurability_System_Single___Boxed {
        struct Tuple_4_MoleMole_ActorModifier_System_Single_MoleMole_IElementDurability_System_Single___Class* klass;
        MonitorData* monitor;
        struct Tuple_4_MoleMole_ActorModifier_System_Single_MoleMole_IElementDurability_System_Single_ fields;
    };

    struct Nullable_1_UniRx_Tuple_4_ {
        struct Tuple_4_MoleMole_ActorModifier_System_Single_MoleMole_IElementDurability_System_Single_ value;
        bool has_value;
    };

    struct IDPLOHKAJML__Fields {
        struct LCBase__Fields _;
        struct Dictionary_2_System_Int32_List_1_MLAAELGDIJH_* _elementModifierMap;
        struct Action* _act;
        struct List_1_System_Nullable_1_* _modifierDurabilities;
        struct List_1_UniRx_Tuple_3__1* _elemAccuDurabilities;
        struct OJGKFFDAGON* _levelAbilityCom;
        struct OJGKFFDAGON* _selfLCAbility;
        struct KMALPDEBPFP* _lcAbilityState;
        struct DGLICFPOFBE* _vcBillboard;
        float _purgeRate;
        float _purgeIncement;
        bool _ignorePurgeRate;
        struct EDDKNGCGJFI* _grassScenePlugin;
        struct EADDBDCPBMJ* _waterScenePlugin;
        struct EBLDCCEGAOF* _bushScenePlugin;
        struct BDFMIJCPDIC* _shakeInterval;
        bool _showReactionText;
        struct String* elementDecrateGroup;
        bool BHDLGGOBAME;
        bool AKLPKDONCJH;
        struct Func_2_MLAAELGDIJH_Boolean_* NEMHEFJLFEA;
        struct Action_3_GLPNBMKEPPD_CCAMDLAOBAA_Nullable_1_UnityEngine_Vector3_* FDHMHGFNCFD;
        struct Action_3_GLPNBMKEPPD_CCAMDLAOBAA_Nullable_1_UnityEngine_Vector3_* NIHADNAGOND;
        struct Vector3 elementReactionPos;
        bool triggerFrozenBroken;
        float _lastCrystallizeTime;
    };

    struct LCAbilityElement {
        struct LCAbilityElement__Class* klass;
        MonitorData* monitor;
        struct IDPLOHKAJML__Fields fields;
    };

    struct Camera__Fields {
        struct Behaviour__Fields _;
    };

    struct Camera {
        struct Camera__Class* klass;
        MonitorData* monitor;
        struct Camera__Fields fields;
    };

    struct Resolution {
        int32_t m_Width;
        int32_t m_Height;
        int32_t m_RefreshRate;
    };

    struct Collider__Array {
        struct Collider__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        struct Collider* vector[32];
    };

    struct Collider__Fields {
        struct Component_1__Fields _;
    };

    struct Collider {
        struct Collider__Class* klass;
        MonitorData* monitor;
        struct Collider__Fields fields;
    };

    struct Behaviour {
        struct Behaviour__Class* klass;
        MonitorData* monitor;
        struct Behaviour__Fields fields;
    };

    struct IGKEDHHIDMA__Fields
    {
        struct BasePageContext__Fields _;
        float EnterCountDown;
        struct String* CountDownPrefab;
        struct GameObject* _CountDownGo;
        struct MonoInLevelProgressBar* _script;
        float _countDownTime;
        uint32_t _handle;
        struct Image* _fillImage;
        struct Coroutine* countCoroutine;
        bool _panelActive;
        bool _countDownAcitve;
        bool _isEndingCountdown;
        struct Nullable_1_MoleMole_AsyncJob_ _countDownLoadingJob;
        int32_t _versusBattleTotle;
        struct CNCFAOMBJIP* _countDown;
        struct EAPNPEGAAII* _inteePanelCom;
        struct AJEAPLJOAON* _directionIndicator;
        struct ELCMPFBKPBA* _targetIndicator;
        struct GDIAIBAJMDC* _gadgetIndicator;
        struct OOKIJPIAEGD* _navigationIndicator;
        struct LNBLFPFIGFF* _galleryPlay;
        struct BPJHCKHOCIO* _quickChangeTeamCom;
        struct MonoParticleDamageTextContainer* _damageParticleTextContainer;
        void* _pageMono;
        struct MonoInLevelLimitRegion* _monoBlackMask;
        struct BEJJFHHKIBA* _newItemDialog;
        struct NBMGJNBMIOA* _specialItemDialog;
        struct MLHLCCGMGOP* _galleryDialog;
        struct GJPBGPGKGNN* _localAvatar;
        struct Button* _transBtn;
        int32_t _lastLayoutVersion;
        bool _canChangeMoveType;
        bool _autoOpenedDungeonFactor;
        bool _forbiddenToggleMoveByState;
        bool _isPaimonNormal;
        bool _isChatEnabled;
        struct MBKDBIHKAGD* chatBubbleDisplayer;
        bool _chatPanelResolved;
        bool _mapActive;
        bool _transAppear;
        struct DateTime _rttRefreshTime;
        struct Color _rttGreen;
        struct Color _rttYellow;
        struct Color _rttRed;
        uint32_t _rttLowLimit;
        uint32_t _rttMidLimit;
        uint32_t _rttHighLimit;
        uint32_t _rttRefreshDeltaTime;
        struct String* KMBJFGJMNMH;
        struct Coroutine* _dungeonItemCoroutine;
        bool _isOpenInputContainer;
        bool _isOpenActionContainer;
        bool _isOpenMessageContainer;
        uint32_t _lastTimeLeft;
        uint32_t _lastCount;
        int32_t combatBarType;
        struct List_1_EJFOBCPHDFP_* _saveCombatsData;
        struct GameObject* m_LightingInfoUI;
        struct GameObject* m_TreeOverdrawInfoUI;
        struct GameObject* m_QuickRenderMenu;
        bool _inShakeOff;
        struct OKGLPFDFCPK* _challengeConfig;
        struct Coroutine* _blossomBeginCoroutine;
        struct MonoTowerHintText* _hintPage;
        struct Coroutine* fleurFairDungeonStartAnimCoroutine;
        float _curFleurFairDungeonBarValue;
        bool _isInFlightChallenge;
        bool _isShowFlightChallengeHint;
        struct OKGLPFDFCPK* _flightSubChallengeConfig;
        bool _waitStart;
        struct Coroutine* _startCoroutine;
        struct Coroutine* _uidCoroutine;
        bool _playUidOpEnd;
        uint32_t _curStage;
        struct HDMIAHJPLCJ* _combat;
        struct Coroutine* _altPressCoroutine;
        struct Coroutine* _cameraLookEndCoroutine;
        bool _disableSkillInput;
        bool _disableMoveInput;
        bool _disableActionInput;
        bool _mapInfoVisible;
        bool _chatInfoVisible;
        struct Dictionary_2_System_Int32_HashSet_1_System_Int32_* _uiDisableStateDic;
        struct Dictionary_2_System_Int32_HashSet_1_System_Int32_* _inputEnableStateDic;
        struct HashSet_1_System_Int32_* _mainPageDisableSet;
        struct DODHAKHMNDK* zoomSmoother;
        struct KOOFBIDHECP* _virtualDialDialog;
        struct NOIFCOKPBBI* AEKMPNKPJCK;
        int32_t _prevState;
        bool _changeWithSkill;
        struct DINCOJBJLML* _messageDialog;
        bool showHazadousWarning;
        struct List_1_DINCOJBJLML_PGCPDEKPCKM_* HGLADPDCIEO;
        struct IKECDNKKMJM* _questHintDialog;
        struct FBCIMPOLFEI* _questProgressDialog;
        struct ECDKKGFNMNF* _rewardDialogGeneral;
        struct ECDKKGFNMNF* _rewardDialogQuest;
        struct ECDKKGFNMNF* _rewardDialogDailyTask;
        struct ECDKKGFNMNF* _rewardDialogRandTask;
        struct ECDKKGFNMNF* _rewardDialogGather;
        struct GCMPGGFPHDJ* _deblockingDialog;
        struct OEBIPCONBLK* _taskTitleDialog;
        struct Coroutine* _templateReminderCoroutine;
        struct PCIKGHOIFOO* _reminderDialog;
        bool HICPKFKAOCK;
        struct Nullable_1_UnityEngine_Vector3_ _targetPos;
        int32_t _lastIntDst;
        bool _pushtipsShowed;
        bool BPENOEMPIBP;
        uint32_t APGMBPPFPDH;
        struct PGGJOHPFKCO* HIJIBGFKGAC;
        bool NLNAHEMFIDM;
        struct MonoMiniMap* _miniMap;
        struct MonoMapFogAreaGrp* _miniMapFog;
        bool _mapImgReady;
        uint32_t _mapImageHandle;
        uint32_t _mapFogHandle;
        struct Dictionary_2_System_Int32_Dictionary_2_System_UInt32_MoleMole_MonoMapMark_* _marks;
        struct HashSet_1_MoleMole_MonoMapMark_* _activeMarks;
        struct HashSet_1_MoleMole_MonoMapMark_* _candidateMarks;
        struct Vector2 _searchRegionCenter;
        struct MonoMapMark* _mapMarkPrefab;
        uint32_t _sceneID;
        float _sqrUpdateSearchDistance;
        float _sqrSearchRegionRadius;
        struct GameObject* _mapImageInst;
        float _miniMapScale;
        float _defaultMiniMapScale;
        struct RectTransform* _miniMapBackImg;
        struct MonoLevelMap* _levelMap;
        struct RectTransform* _levelMapTrans;
        struct Vector2 rectSize;
        struct Coroutine* _setScaleCoroutine;
        float _currTime;
        float _tweenTime;
        float _targetScale;
        float _preScale;
        bool _forceUpdateMark;
        struct Vector3 _lastPlayerPos;
        float _lastCameraAngle;
        float _lastAvatarAngle;
        struct BaseEntity* _teamEntity;
        struct Transform* _cameraTrans;
        float _markContainerLocalEulerAngleZ;
        bool updateCamera;
        struct Vector3 newEulerAngle;
        int32_t _lastFixType;
        struct HashSet_1_System_UInt32_* _fakemarkTobeRemoved;
        bool _mapBackRotateDirty;
        bool _mapContainerDiry;
        bool _isSignalActive;
        float _checkInterval;
        float _checkTime;
        float _lastDistance;
        float _audioTime;
        float _audioPeriod;
        uint32_t _signalAudioID;
        struct String* miniMapQuestMarkPath;
        struct Dictionary_2_System_UInt32_MoleMole_MonoMapMark_* _fakeMarkDic;
        uint32_t _fakeMarkHandle;
        float _sightWorldRadius_k__BackingField;
        float _markReachToUIRatio_k__BackingField;
        float _worldUnitPerPixel_k__BackingField;
        bool _questEnable;
        struct Coroutine* _spPresstartCoroutine;
        uint64_t _currentAvatarID;
        struct List_1_MoleMole_MonoTeamBtn_* _buttonList;
        struct List_1_System_UInt64_* _avatarGuidList;
        bool _showChangeAvatarCDText;
        int32_t _count;
        struct List_1_MoleMole_MonoMPTeamBtn_* teamBtnList;
        bool _hideTeamBtnName;
        float HFFMDBPJNCL;
        struct Dictionary_2_System_Int32_Queue_1_MoleMole_BaseContext_* _widgetQueueDic;
        float DELAY_TIME;
        struct Action* _onSetActiveHandler;
    };

    struct InLevelMainPageContext
    {
        struct IGKEDHHIDMA__Class* klass;
        MonitorData* monitor;
        struct IGKEDHHIDMA__Fields fields;
    };

    struct MonoMiniMap__Fields {
        struct MonoBehaviour__Fields _;
        struct Button* _actionButton;
        struct RectTransform* _grpMap;
        struct RectTransform* _grpMapBack;
        struct RectTransform* _markContainer;
        struct RectTransform* _unusedMarkContainer;
        struct RectTransform* _maskedMarkLayer;
        struct RectTransform__Array* _markContainerLayers;
        struct RectTransform* _localAvatarMark;
        struct RectTransform* _sightFanMark;
        struct RectTransform* _directionMark;
        struct RectTransform* _grpMiniBackRotate;
        struct Image* _imgMiniBack;
        float _areaMinDistance;
        struct Queue_1_MoleMole_MonoMapMark_* _unusedMarkPool;
        struct MonoMapMark* _markPrefab;
        struct RectTransform* _hazardousArea;
        float _warningCooldown;
        float _warningTime;
        bool _isWarning;
        struct InLevelMainPageContext* context;
    };

    struct MonoMiniMap {
        struct MonoMiniMap__Class* klass;
        MonitorData* monitor;
        struct MonoMiniMap__Fields fields;
    };

    struct RectTransform__Fields {
        struct Transform__Fields _;
    };

    struct RectTransform {
        struct RectTransform__Class* klass;
        MonitorData* monitor;
        struct RectTransform__Fields fields;
    };

    struct Quaternion__Boxed {
        struct Quaternion__Class* klass;
        MonitorData* monitor;
        struct Quaternion fields;
    };

    enum class InteractType__Enum : int32_t {
        InteractNone = 0x00000000,
        InteractPickItem = 0x00000001,
        InteractGather = 0x00000002,
        InteractOpenChest = 0x00000003,
        InteractOpenStatue = 0x00000004,
        InteractConsum = 0x00000005,
        InteractMpPlayReward = 0x00000006,
        InteractView = 0x00000007,
        InteractGeneralReward = 0x00000008,
        InteractMiracleRing = 0x00000009,
        InteractFoundation = 0x0000000a,
        InteractEchoShell = 0x0000000b,
        InteractHomeGather = 0x0000000c,
        InteractEnvAnimal = 0x0000000d,
        InteractQuestGadget = 0x0000000e,
        LGHNPMNCLLI = 0x0000000f,
    };

    enum InterOpType__Enum {
        InterOpType__Enum_InterOpFinish = 0x00000000,
        InterOpType__Enum_InterOpStart = 0x00000001,
    };

    struct GadgetInteractRsp__Fields {
        struct MessageBase_1__Fields _;
        int32_t retcode_;
        uint32_t gadgetEntityId_;
        InteractType__Enum interactType_;
        InterOpType__Enum opType_;
        uint32_t gadgetId_;
    };

    struct GadgetInteractRsp {
        struct GadgetInteractRsp__Class* klass;
        MonitorData* monitor;
        struct GadgetInteractRsp__Fields fields;
    };

    struct EntityHandle_1_BaseEntity_ {
        uint32_t runtimeID;
        struct BaseEntity* _entityRef;
    };

    struct GGGIOOJFONN_CCAMDLAOBAA_ {
        uint32_t ODBALKCAMHN;
        struct CCAMDLAOBAA* KCIDMFKGBFB;
    };

    struct __declspec(align(8)) FishingManager__Fields {
        struct DBEHAHEIEIP__Array* _levelFishBait;
        struct UInt32__Array* _failedReminder;
        struct UInt32__Array* _preSuccessReminder;
        struct UInt32__Array* _star3Reminder;
        struct UInt32__Array* _star4Reminder;
        float _lastPreSuccessTime;
        uint32_t _lastPreSuccessReminder;
        uint32_t baitId;
        uint32_t rodId;
        uint32_t _rodEntityId;
        uint32_t poolId;
        uint32_t poolEntityId;
        uint32_t fishRuntimeId;
        bool _enterPosChecked;
        struct Vector3 _enterPos;
        float _curForce_k__BackingField;
        float _curDmg_k__BackingField;
        float _lastForce;
        float _baseAddForce;
        float _addForceAcce;
        float _addForceMax;
        float _addForceStartTime;
        float _addForceTime;
        float _curAddForce;
        float _baseReduceForce;
        float _reduceForceAcce;
        float _reduceForceMax;
        float _reduceForceStartTime;
        float _reduceForceTime;
        float _curReduceForce;
        float _forceFactorX;
        float _baseAddAtk;
        float _addAtkAcce;
        float _addAtkMax;
        float _curAddAtk;
        float _baseReduceAtk;
        float _dmgFactorX;
        float _triggerInterval;
        float _releaseInterval;
        int32_t _inBonusFlag;
        float _enterBonusTime;
        float _maxBonusTime;
        bool _isEnterFishing_k__BackingField;
        bool _isFishing;
        bool _isCastingAnchorPoint_k__BackingField;
        float _maxDmg;
        float _triggerTime;
        float _releaseTime;
        float _damageZeroTimeStart;
        float _lastWarnningTime;
        uint32_t _strength;
        struct GGGIOOJFONN_CCAMDLAOBAA_ _fishHandle;
        float LEFNBAMIIFA;
        float IAGEFBOLFGL;
        float _bonusCenter;
        float _bonusRadius;
        float _curBonusRadius_k__BackingField;
        float _bonusRadiusSpeed;
        float _bonusRadiusTime;
        float _bonusSpeed;
        float _bonusTarget;
        float _bonusDir;
        float _bonusTime;
        float _bonusDuration;
        struct Vector2 _bonusDurationRange;
        struct Vector2 _bonusOffsetRange;
        struct Vector2 _bonusSpeedRange;
        float _curBonusSpeed;
        float _bonusStartAcc;
        float _bonusEndAcc;
        float _bonusMoveDst;
        struct LJHBAOBBLDE* _fishConfig;
        bool _dmgStart;
        uint64_t _qteStartTime;
        int32_t _tipsFlag;
        struct List_1_HJJINBLMFFC_BDBAIICPIMN_* _skillList;
        struct HJJINBLMFFC_BDBAIICPIMN* _curForceSkill;
        struct HJJINBLMFFC_BDBAIICPIMN* _curBonusSkill;
        struct PCIKGHOIFOO* _generalDialogContext;
    };

    struct FishingManager {
        struct FishingManager__Class* klass;
        MonitorData* monitor;
        struct FishingManager__Fields fields;
    };

    struct FishBiteRsp__Fields {
        struct MessageBase_1__Fields _;
        int32_t retcode_;
    };

    struct FishBiteRsp {
        struct FishBiteRsp__Class* klass;
        MonitorData* monitor;
        struct FishBiteRsp__Fields fields;
    };

    struct FishBattleBeginRsp__Fields {
        struct MessageBase_1__Fields _;
        int32_t retcode_;
    };

    struct FishBattleBeginRsp {
        struct FishBattleBeginRsp__Class* klass;
        MonitorData* monitor;
        struct FishBattleBeginRsp__Fields fields;
    };

    enum class FishBattleResult__Enum : int32_t {
        None = 0x00000000,
        Succ = 0x00000001,
        Fail = 0x00000002,
        Timeout = 0x00000003,
        Cancel = 0x00000004,
        Exit = 0x00000005,
    };

    enum class FishingEvent__Enum : int32_t {
        None = 0x00000000,
        QteStart = 0x00000001,
        QteTrigger = 0x00000002,
        RequestQuit = 0x00000003,
        CastAnchorPoint = 0x00000004,
        SelectBait = 0x00000005,
        Pull = 0x00000006,
        NotifyBait = 0x00000007,
    };

    struct FishBattleEndRsp__Fields {
        struct MessageBase_1__Fields _;
        int32_t retcode_;
        FishBattleResult__Enum battleResult_;
        /*
        bool isGotReward_;
        FishBattleEndRsp_DFMONJENODL_BCGICPPBNDK__Enum noRewardReason_;
        struct JKGMNHEOCKM_Proto_ItemParam_* rewardItemList_;
        struct JKGMNHEOCKM_Proto_ItemParam_* dropItemList_;
        struct JKGMNHEOCKM_Proto_ItemParam_* talentItemList_;
        */
    };

    struct FishBattleEndRsp {
        struct FishBattleEndRsp__Class* klass;
        MonitorData* monitor;
        struct FishBattleEndRsp__Fields fields;
    };

    enum class DataPropOp__Enum : int32_t {
        Reset = 0x00000000,
        Change = 0x00000001,
    };

    struct __declspec(align(8)) NormalTimer__Fields {
        float _timer_k__BackingField;
        float _timespan_k__BackingField;
        bool _isTimeUp_k__BackingField;
        bool _isActive_k__BackingField;
        struct Action* timeupAction;
        bool fromCache;
    };

    struct NormalTimer {
        struct NormalTimer__Class* klass;
        MonitorData* monitor;
        struct NormalTimer__Fields fields;
    };

    struct EntityTimer__Fields {
        struct NormalTimer__Fields _;
        struct BaseEntity* _timeScaleEntity;
        bool _ignoreTimeScale;
    };

    struct EntityTimer {
        struct EntityTimer__Class* klass;
        MonitorData* monitor;
        struct EntityTimer__Fields fields;
    };

    struct LCCharacterCombat__Fields {
        struct LCBaseCombat__Fields _;
        struct Dictionary_2_System_UInt32_MoleMole_LCCharacterCombat_NOCCPOEFFII_* _summonInfos;
    };

    struct LCCharacterCombat {
        struct LCCharacterCombat__Class* klass;
        MonitorData* monitor;
        struct LCCharacterCombat__Fields fields;
    };

    struct __declspec(align(8)) LCAvatarCombat_OMIIMOJOHIP__Fields {
        uint32_t skillID;
        struct AvatarSkillExcelConfig* config;
        struct SafeFloat cdTimer;
        struct SafeFloat currChargeCount;
        struct SafeFloat costStamina;
        bool canHold;
        bool canTrigger;
        bool useInAir;
        struct HashSet_1_System_Int32_* canUseSkillStateWhiteList;
        int32_t needMonitor;
        bool isLocked;
        bool ignoreCDMinusRatio;
        bool forceCanDoSkill;
        struct SafeFloat NFNMNLKPNHD;
        struct SafeFloat EBIABBHAFFD;
        struct SafeFloat HPDKMHFJFMI;
        struct SafeFloat IBKPGNDMDBJ;
        struct SafeFloat GBGBNALDDFM;
        int32_t skillIndex;
        int32_t prority;
        float _costElem_k__BackingField;
        int32_t _maxChargeCount_k__BackingField;
    };

    struct LCAvatarCombat_OMIIMOJOHIP {
        struct LCAvatarCombat_OMIIMOJOHIP__Class* klass;
        MonitorData* monitor;
        struct LCAvatarCombat_OMIIMOJOHIP__Fields fields;
    };

    struct LCAvatarCombat__Fields {
        struct EntityTimer* _targetAtteTimer;
        struct EntityTimer* _targetFixTimer;
        struct Config_AvatarSkillDepotExcelConfig* _skillDepotConfig;
        bool toDoChargeSkill;
        struct LCAvatarCombat_SkillInfo__Array* _currSkills;
        struct Dictionary_2_System_UInt32_SafeFloat_* _equipAffixCD;
        int32_t _attackModeTriggerID;
        struct Dictionary_2_System_UInt32_LCAvatarCombat_SkillInfo_* _skillInfoMap;
        struct List_1_System_ValueTuple_2__3* _affixToAdd;
        struct BaseShape2d* _curLockTargetShape;
        struct SimpleSafeFloat__Array* _curLockTargetWeightParams;
        void* _lockTargetOverrideParams;
        struct List_1_LCAvatarCombat_LCAvatarCombat_HitBucketItem_* meleeBuckets;
        struct List_1_LCAvatarCombat_LCAvatarCombat_HitBucketItem_* rangedBuckets;
        struct Dictionary_2_System_UInt32_List_1_System_UInt32_* _curSkillCDSlot;
    };

    struct LCAvatarCombat {
        struct LCAvatarCombat__Class* klass;
        MonitorData* monitor;
        struct LCAvatarCombat__Fields fields;
    };

    enum class HumanoidMoveFSM_HumanoidMoveFSM_FSMStateID__Enum : int32_t {
        Move = 0x00000000,
        TurnDirection = 0x00000001,
        FallOnGround = 0x00000002,
        GoUpstairs = 0x00000003,
        JumpUpWallReady = 0x00000004,
        Climb = 0x00000005,
        JumpUpWallForStandby = 0x00000006,
        StandbyToClimb = 0x00000007,
        Jump = 0x00000008,
        Drop = 0x00000009,
        Fly = 0x0000000a,
        CombatMove = 0x0000000b,
        CombatFallOnGround = 0x0000000c,
        CombatAir = 0x0000000d,
        Swim = 0x0000000e,
        SwimJump = 0x0000000f,
        Ladder = 0x00000010,
        FlyGateLoading = 0x00000011,
        Crouch = 0x00000012,
        Perform = 0x00000013,
        FlyFollowRoute = 0x00000014,
        Null = 0x00000015,
        Vehicle = 0x00000016,
        Skiff = 0x00000017,
    };

    struct HumanoidMoveFSM__Fields {
        struct BaseComponentPlugin__Fields _;
        struct HumanoidMoveFSMBaseMoveState* _curState;
        int32_t fallOnGroundFirstFrame;
        struct Dictionary_2_MoleMole_HumanoidMoveFSM_JJLCCKKCHPD_MoleMole_HumanoidMoveFSMBaseMoveState_* stateMapInfo;
        struct VCHumanoidMoveData* _moveData;
        struct VCHumanoidMoveConfig* _moveConfig;
        struct VCHumanoidMove* _ownerMove;
        struct Animator* _animator;
        struct Rigidbody* _rigidbody;
        struct AnimatorController* _animatorController;
        void* OnMoveUpdateCallback;
        void* OnAirUpdateCallback;
        bool _initSyncWithCurrentTask;
        bool _behaviourSet;
        float _sendCombatNotifyTime;
        bool enterSprintBS;
        bool _positionRotationChanged_k__BackingField;
        struct Transform* _transform;
        struct Vector3 lateTickStartPosition;
        struct Quaternion lateTickStartRotation;
        int32_t _layerMaskScene;
        int32_t _layerMaskDynamicBarrier;
        int32_t layerMaskDynamicBarrierCheckAuthority;
        bool ignoreOverallMoveWallProtectionCurrentFrame;
        bool stopMoveWhenGoupstairs;
        bool lastStopMoveWhenGoupstairs;
        float climbGlobalRecovery;
        bool autoGoUpstair;
        bool forceDoNotSyncWhenReset;
        float inSprintTime;
        int32_t _lastCurrentStateHash;
        int32_t _lastNextStateHash;
        bool _firstLatetick;
        bool _lastInForbiddenToggleMoveState;
        bool _disableMotion4hiUpdateCurrentFrame;
        int32_t _flyStateHash;
        struct VCMoveIKController* _ikComp;
        struct Transform* _lCalf;
        struct Transform* _rCalf;
        void* _weaponStandbyIKParams;
        void* _normalStandbyIKParams;
        void* _params;
        float _lastSkirtBlendParam;
        float _idealSkirtBlendParam;
        float _lastIdealSkirtBlendParam;
        float _lastSkirtWeight;
        float _idealSkirtWeight;
        float _lastSkirtPos;
        float _idealSkirtPos;
        void* _lastFrameAnimSpeedInfo;
        void* _currentFrameAnimSpeedInfo;
        bool _isInSprintCheckInterval;
        bool _isInMuteSprintInterval;
        float _timeAfterLastSprint;
        uint32_t _lastFrameVelocityCheckBits;
        bool _lastFrameVelocityCheckResult;
        bool _remoteCheckLightCoreMove;
        struct Vector3 _remoteCheckLightCoreMoveTarget;
    };

    struct HumanoidMoveFSM {
        struct HumanoidMoveFSM__Class* klass;
        MonitorData* monitor;
        struct HumanoidMoveFSM__Fields fields;
    };

    struct SCameraModuleInitialize__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData PODDMLNOAIC;
        VirtualInvokeData CJFDOKANFFO;
        VirtualInvokeData MODBDHFJMMK;
        VirtualInvokeData BDEMLMONJLP;
        VirtualInvokeData CEONIHCAFLE;
        VirtualInvokeData EKNGAGLAGDO;
        VirtualInvokeData FEECLIEHIMB;
        VirtualInvokeData BDCBKMLNFBH;
        VirtualInvokeData HHLKFCNMNFF;
        VirtualInvokeData HJIDOMGOCNO;
        VirtualInvokeData HIDLLHBHACG;
    };

    struct SCameraModuleInitialize__StaticFields {
        struct DelegateBridge* MGFFCDGAIDM;
        struct DelegateBridge* EMPDBKKFDEH;
        struct DelegateBridge* LJFCBJFECIM;
        struct DelegateBridge* OBDMMEOIDDD;
        struct DelegateBridge* PMLMIEOEAEI;
        struct DelegateBridge* ACDKGBLBOPF;
        struct DelegateBridge* GJGHGIEECBJ;
        struct DelegateBridge* KMNDONNIDOG;
        struct DelegateBridge* EDKBBBAPKNK;
        struct DelegateBridge* LCCJOCOOPNG;
        struct DelegateBridge* DPMMFLGDGIE;
        struct DelegateBridge* CIADAMOHLOO;
        struct DelegateBridge* EJMEFEDPGKO;
        struct DelegateBridge* CGKHIGGPGDI;
        struct DelegateBridge* NHMJOEBDCOO;
        struct DelegateBridge* KKHKGALGNBF;
        struct DelegateBridge* MIBGPOOPJLI;
        struct DelegateBridge* IDKHBEDAJPF;
        struct DelegateBridge* GKJOJNEECDM;
        struct DelegateBridge* ADEPIOCJMPN;
        struct DelegateBridge* LBCLKFHBHIE;
        struct DelegateBridge* HAOKFADIBCF;
        struct DelegateBridge* CNCLDMPOFAJ;
        struct DelegateBridge* DPJPHBIHEFA;
        struct DelegateBridge* KHHAOEIFDAP;
        struct DelegateBridge* POLIPAAFCPA;
        struct DelegateBridge* FPOCACECFCG;
        struct DelegateBridge* IFLPBMPEBCN;
        struct DelegateBridge* MHKCECLNCOD;
        struct DelegateBridge* LIDKADPGCFA;
        struct DelegateBridge* KDCPGFEEFCL;
        struct DelegateBridge* FKAONMCKIBP;
        struct DelegateBridge* FEDMEBPGJFE;
        struct DelegateBridge* IDBHCJFAOHO;
        struct DelegateBridge* IBBBMCNODMJ;
        struct DelegateBridge* HAOKOPOHLHJ;
        struct DelegateBridge* GPABAMGACIH;
    };

    struct SCameraModuleInitialize__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct SCameraModuleInitialize__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct SCameraModuleInitialize__VTable vtable;
    };

    struct __declspec(align(8)) SCameraModuleBase__Fields {
        struct PipelineCameraModuleConfig* config;
        struct PipelineCameraGlobalConfig* globalConfig;
        struct SCameraBaseState* _state;
    };

    struct SCameraModuleInitialize__Fields {
        struct SCameraModuleBase__Fields _;
        bool levelCinemachine;
        struct SimpleVector3Damper* _skfilter;
        bool _isFilterInitialized;
        bool _isTrySmoothBetweenNormalAndClimb;
        double _smoothLerpSpeed;
        struct Vector3d_1 _smoothingTransformLookAtPoint;
        struct SimpleKalmanFilter* _dirKfilter;
        bool _isDirectionFilterInitialized;
        struct Vector3d__Array* _faceDirectionTrace;
        bool _isFaceDirectionTraceInitialized;
        struct Vector3d_1 _lastFrameSmoothFaceDirection;
        bool _hasEnteredAvatarClimb;
        bool _hasBeenConsistent;
        double _timerForWaitingFacingToWallNoraml;
#if defined(_CPLUSPLUS_)
        HumanoidMoveFSM_HumanoidMoveFSM_FSMStateID__Enum _curFSMState;
#else
        int32_t _curFSMState;
#endif
#if defined(_CPLUSPLUS_)
        HumanoidMoveFSM_HumanoidMoveFSM_FSMStateID__Enum _lastFSMState;
#else
        int32_t _lastFSMState;
#endif
        struct Vector3d_1 _climbWallNormal;
        bool _climbWallNormalGetted;
        int32_t _LayerIndex;
        int32_t _SceneLayerIndex;
        struct Ray _ray;
        struct RaycastHit _hitInfo;
        double _timerForDropping;
        bool _firstStartFlag;
        bool _isMoving;
        bool _isDropping;
        bool _isCombatHitCamera;
        bool _isInStandby2Climb;
        bool _isWaterFall;
        double _waterHeight;
        struct Vector3d_1 _waterFallNormal;
        struct Vector3d_1 _avatarVelocity;
        bool _isAvatarMoveFollowRefferenceSystem;
        double _inputMoveAngle;
        double _inputMoveMold;
        double _defaultCameraDistanceAdjust;
        float HOBOHFMFPPG;
        float POIEBBJDKKF;
        bool DJDBLKBDMAH;
        struct Dictionary_2_UnityEngine_Vector2_System_Double_* _animStateChangePair;
        struct Dictionary_2_UnityEngine_Vector2_SCameraModuleInitialize_SCameraModuleInitialize_FilterKeepType_* _animStateChangeType;
        struct Dictionary_2_UnityEngine_Vector2_System_Double_* _animStateChangeTime;
        double _preNormalRadiusTarget;
        double _preNormalRadiusStart;
        double _deltaTimeNormal;
        bool _lerpingNormal;
        struct Vector3d_1 heightAdjust;
        struct Vector3d_1 heightAdjustMax;
        struct Vector3d_1 currHeightAdjust;
    };

    struct SCameraModuleInitialize {
        struct SCameraModuleInitialize__Class* klass;
        MonitorData* monitor;
        struct SCameraModuleInitialize__Fields fields;
    };

    struct __declspec(align(8)) SimpleVector3Damper__Fields {
        struct Vector3d_1 _lastPosition;
        struct Vector3d_1 _lastTargetPosition;
        struct Vector3d_1 _lastVelocity;
        double _dampTime;
    };

#if defined(_CPLUSPLUS_)
    enum class CameraModuleState__Enum : int32_t {
        Normal = 0x00000000,
        Parallel = 0x00000001,
        Cinema = 0x00000002,
    };

#else
    enum CameraModuleState__Enum {
        CameraModuleState__Enum_Normal = 0x00000000,
        CameraModuleState__Enum_Parallel = 0x00000001,
        CameraModuleState__Enum_Cinema = 0x00000002,
    };

#endif

    enum class HNGOGENCDGD__Enum : int32_t {
        None = 0x00000000,
        LerpingIn = 0x00000001,
        Free = 0x00000002,
        LerpingOut = 0x00000003,
    };

    struct CameraShareData {
        int32_t targetFrameRate;
        bool isBackground;
        bool isBlending;
        bool disableProtect;
#if defined(_CPLUSPLUS_)
        CameraModuleState__Enum state;
#else
        int32_t state;
#endif
#if defined(_CPLUSPLUS_)
        CameraModuleState__Enum lastFrameState;
#else
        int32_t lastFrameState;
#endif
        double anchorDistance;
        double defaultHalfFov;
        double CameraNearClipPlane;
        double CameraHalfFov;
        double CameraAspect;
        double BoatFov;
        struct Vector3d_1 outCameraPosition;
        struct Vector3d_1 outCameraSpherical;
        struct Vector3d_1 outCameraForward;
        struct Vector3d_1 outCameraUp;
        struct Vector3d_1 cameraPosition;
        struct Vector3d_1 cameraSpherical;
        struct Vector3d_1 cameraForward;
        struct Vector3d_1 cameraUp;
        struct Vector3d_1 refAnchorPosition;
        struct Vector3d_1 lastCameraPosition;
        struct Vector3d_1 lastCameraSpherical;
        struct Vector3d_1 lastCameraForward;
        struct Vector3d_1 lastCameraUp;
        struct Vector3d_1 lastRefAnchorPosition;
        struct Vector3d_1 lastFrameCameraPosition;
        struct Vector3d_1 lastFrameCameraSpherical;
        struct Vector3d_1 lastFrameCameraForward;
        struct Vector3d_1 lastFrameCameraUp;
        struct Vector3d_1 lastFrameRefAnchorPosition;
        double cameraForwardPoleDeltaAngle;
        double cameraForwardElevDeltaAngle;
        double lastFrameCameraForwardPoleDeltaAngle;
        double lastFrameCameraForwardElevDeltaAngle;
        struct Vector3d_1 lastFrameFilterLookAtPosition;
        struct Vector3d_1 lastFrameLookAtPosition;
        struct Vector3d_1 lastFrameTransformLookAtPosition;
        double additionalRadius;
        double globalDefaultCameraLocateRatio;
        double currentManualLocateRatio;
        double currentHeightAdjustRatio;
        double currentWarningLocateRatio;
        double maxRadiusAjustRatio;
        double _defaultRadiusExtraRatio;
        double _maxRadiusExtraRatio;
        double _maxRadiusNormal;
        double _defaultLocateRatioNormal;
        double _maxRadiusCombat;
        double _minCameraRadius;
        double maxRadiusNormalInLerping;
        double maxRadiusCombatInLerping;
        double globalDefaultElevation;
        double globalMinElevation;
        double globalMaxElevation;
        bool CNNNLIMHHKK;
        bool EPCDPKNLHEA;
#if defined(_CPLUSPLUS_)
        HNGOGENCDGD__Enum CJOOGBBKNPM;
#else
        int32_t CJOOGBBKNPM;
#endif
#if defined(_CPLUSPLUS_)
        HNGOGENCDGD__Enum LMKHMGGMCGF;
#else
        int32_t LMKHMGGMCGF;
#endif
        bool DDFJOMJBMEE;
        struct Vector3d_1 DPEJMKOAAKG;
        bool isAvatarFocusing;
        bool isRotating;
        bool isManuallyRotating;
        bool isZooming;
        bool isMoving;
        bool isFlying;
        bool isDropping;
        bool isJumping;
        bool isBeingHit;
        bool isTransfering;
        bool isKeepShotRotation;
        bool isMovingRotatingVertically;
        bool isSkiffDashing;
        bool lastIsRotating;
        bool lastIsZooming;
        bool lastIsMoving;
        bool lastIsFlying;
        bool rotatedDuringCurrentMove;
        bool rotatedDuringCurrentIdle;
        int32_t lastAnimStateInd;
        int32_t curAnimStateInd;
        bool setFilterAnimStateFlag;
        struct Vector2 refAnchorAngularVelocity;
        double zoomVelocity;
        bool needFastGotoIdealDir;
        bool idealClimb2Move;
        bool isSpecifyPoleClockwise;
        bool isCounterClockwise;
        bool isBoatRecovering;
        int32_t lockingEnemyNearbyCount;
        double lockingEnemyHeight;
        bool paraKeepYaw;
        bool shouldKeepElevationRotating;
        bool isInBackUpSlope;
        double idealSlope;
        bool isKeepElevation;
        bool shouldKeepZooming;
        bool isRadiusSqueezing;
        double idealCameraSphZoomRadius;
        double idealCameraSphElevation;
        double radiusBeforeMotion;
        bool isCombatCamera;
        bool isInCombat;
        bool isLocalVehicleInCombat;
        bool isKeepRotation;
        struct Nullable_1_Double_ horizontalRecenteringKeepRotationTriggerTimer;
        struct Nullable_1_Double_ verticalRecenteringKeepRotationTriggerTimer;
        double horizontalRecenteringTriggerTimer;
        double verticalRecenteringTriggerTimer;
        bool isCombatPulling;
        double combatPullingTime;
        struct Nullable_1_Double_ _overrideMinCameraRadius;
        struct Nullable_1_Double_ _overrideMinElevation;
    };

    struct LCIndicatorPlugin__Fields {
        struct BaseComponentPlugin__Fields _;
        void* _timeCheckConditionKeys;
        void* allConditions;
        void* _owner;
        bool unknow;
        void* _levelGadget;
        struct GadgetDataItem* _dataItem;
        void* _tempLateData;
        void* _configIndicator;
        void* indicatorDominators;
        bool _isIndicatorShow;
        void* _checkTimer;
    };

    struct LCIndicatorPlugin {
        struct LCIndicatorPlugin__Class* klass;
        MonitorData* monitor;
        struct LCIndicatorPlugin__Fields fields;
    };

    struct PlayerCookRsp__Fields {
        struct MessageBase_1__Fields _;
        int32_t retcode_;
        struct CookRecipeData_1* recipeData_;
        void* itemList_;
        uint32_t qteQuality_;
        uint32_t cookCount_;
        void* extralItemList_;
    };

    struct PlayerCookRsp {
        struct PlayerCookRsp__Class* klass;
        MonitorData* monitor;
        struct PlayerCookRsp__Fields fields;
    };

    struct MonoCookingQTEPage__Fields {
        struct MonoUIProxy__Fields _;
        struct MonoElementSwitch* _elementSwitch;
        struct Transform* _cookNeedRoot;
        struct GameObject* _addInfo;
        struct Text* _addDescText;
        struct GameObject* _iconState;
        struct Transform__Array* _foodPanel;
        struct MonoUIContainer* _makeBtn;
        struct MonoUIContainer* _autoMakeBtn;
        struct MonoUIContainer* _returnBtn;
        struct GameObject* _qtePanel;
        struct GameObject* _manualQteRoot;
        struct GameObject* _autoQteRoot;
        struct MonoCookGotPanel* _cookGotPanel;
        struct Button* _endBtn;
        struct RectTransform* _goodAreaTrans;
        struct SmoothMask* _goodAreaFill;
        struct RectTransform* _perfectAreaTrans;
        struct SmoothMask* _perfectAreaFill;
        struct RectTransform* _pointerTrans;
        float _qteTime;
        float _autoQteTime;
        float _starQteDelay;
        struct GameObject* _selectNumberRoot;
        struct GameObject* _grpProficiency;
        struct Text* _proficiencyText;
        struct MonoUIContainer* _replaceBtn;
        struct MonoBagProxySlot* _curRecipeItemSlot;
        struct Text* _curRecipeFoodNum;
        struct GameObject* _grpResult;
        struct GameObject* _bonusAdditionalInfoIcon;
        struct Text* _additionalInfoText;
        struct GameObject* _grpJoypadButtons;
        struct GameObject* _bagSlotPrefab;
        struct List_1_MoleMole_MonoItemSlot_* _cookNeedList;
        struct MonoCookAvatarSelect* _avatarPanel;
        struct MonoAvatarIcon* _avatarIcon;
        struct Transform* _avatarIconRoot;
    };

    struct MonoCookingQTEPage {
        struct MonoCookingQTEPage__Class* klass;
        MonitorData* monitor;
        struct MonoCookingQTEPage__Fields fields;
    };

    struct CookingQtePageContext__Fields {
        struct BasePageContext__Fields _;
        struct MonoCookingQTEPage* _pageMono;
        uint32_t _recipeId;
        uint32_t _avatarId;
        float _goodRangeStart;
        float _goodRangeEnd;
        float _perfectRangeStart;
        float _perfectRangeEnd;
        bool _qteStart;
        float _qteTime;
        float _qteBonusRange;
        bool _isAuto;
        int32_t _foodKind;
        uint32_t _oldProficiency;
        uint32_t _newProficiency;
        uint32_t _maxProficiency;
        uint32_t _curProficiency;
        bool _upProficiencyStart;
        float _upProficiencyTime;
        bool _focusOnNeedItem;
        int32_t _needItemIndex;
        bool canAutoCook;
        struct List_1_MoleMole_SimpleItemStruct_* _itemGotList;
        bool _isAvatarPanelOpen;
        uint32_t _toSelectAvatarId;
        int32_t _toSelectAvatarIndex;
        struct List_1_System_UInt32_* _avatarList;
    };

    struct CookingQtePageContext {
        struct CookingQtePageContext__Class* klass;
        MonitorData* monitor;
        struct CookingQtePageContext__Fields fields;
    };

    struct CookRecipeData_1__Fields {
        struct MessageBase_1__Fields _;
        uint32_t recipeId_;
        uint32_t proficiency_;
    };

    struct CookRecipeData_1 {
        struct CookRecipeData_1__Class* klass;
        MonitorData* monitor;
        struct CookRecipeData_1__Fields fields;
    };

    struct __declspec(align(8)) CookRecipeExcelConfig__Fields {
        struct SimpleSafeUInt32 idRawNum;
        uint32_t _nameTextMapHash;
        struct SimpleSafeUInt32 rankLevelRawNum;
        struct String* _icon;
        uint32_t _descTextMapHash;
        struct UInt32__Array* _effectDesc;
        int32_t _foodType;
        int32_t _cookMethod;
        bool _isDefaultUnlocked;
        SimpleSafeUInt32 maxProficiencyRawNum;
        struct IdCountConfig__Array* _qualityOutputVec;
        struct IdCountConfig__Array* _inputVec;
        struct String* _qteParam;
        struct SimpleSafeUInt32__Array* _qteQualityWeightVec;
    };

    struct CookRecipeExcelConfig {
        struct CookRecipeExcelConfig__Class* klass;
        MonitorData* monitor;
        struct CookRecipeExcelConfig__Fields fields;
    };

    struct CriwareMediaPlayer__Fields {
        struct MonoBehaviour__Fields _;
        struct FDNEMKPLJJP* _eventCallback_k__BackingField;
        struct AspectRatioFitter* _parentAspectRatioFitter;
        struct AspectRatioFitter* _aspectRatioFitter;
        struct Image_1* _image;
        struct Text* _text;
        struct CriManaMovieControllerForUI* _controllerForUI;
        struct CriWareInitializer* _criwareInitializer;
        struct CriWareErrorHandler* _criwareErrorHandler;
        struct VideoSubtitles* _videoSubtitles;
        int32_t _lastStatus; // Player_Status__Enum
        struct Action_1_String_* _onStartPlay;
        struct Action_1_String_* _onFinishPlay;
        struct Action_1_String_* _onError;
        struct Action* _onClose;
        struct String* _videoRuntimePath;
        bool _useSubtitle;
        struct String* _subtitleRuntimePath;
        struct String* _stat;
        int32_t _audioTrack;
        int32_t KBIMMFBKMJE; // KIPKAJKIFKJ__Enum
        uint64_t _encryptKey;
        bool _audioEncrypted;
    };

    struct CriwareMediaPlayer {
        struct CriwareMediaPlayer__Class* klass;
        MonitorData* monitor;
        struct CriwareMediaPlayer__Fields fields;
    };

    struct Sprite__Fields {
        struct Object_1__Fields _;
    };

    struct Sprite {
        struct Sprite__Class* klass;
        MonitorData* monitor;
        struct Sprite__Fields fields;
    };

    struct Texture__Fields {
        struct Object_1__Fields _;
    };

    struct Texture2D__Fields {
        struct Texture__Fields _;
    };

    struct Texture2D {
        struct Texture2D__Class* klass;
        MonitorData* monitor;
        struct Texture2D__Fields fields;
    };

     
  

    struct Image_1__Fields {
        struct MaskableGraphic__Fields _;
        struct Sprite* m_CachedSprite;
        struct Sprite* m_Sprite;
        struct Sprite* m_OverrideSprite;
        int32_t m_Type;
        bool m_PreserveAspect;
        bool m_FillCenter;
        int32_t m_FillMethod;
        float m_FillAmount;
        bool m_FillClockwise;
        int32_t m_FillOrigin;
        float m_AlphaHitTestMinimumThreshold;
        bool m_Tracked;
    };

    struct Image_1 {
        struct Image_1__Class* klass;
        MonitorData* monitor;
        struct Image_1__Fields fields;
    };

    struct MonoInLevelPlayerProfilePage__Fields {
        struct MonoUIProxy__Fields _;
        struct Text* _playerName;
        struct Text* _playerLv;
        struct Text* _playerExp;
        struct Slider_1* _playerExpSlider;
        struct Text* _playerID;
        struct Text* _playerCost;
        struct Text* _playerInfo;
        struct Text* _playerNum;
        struct Image_1* playerIconImage;
        struct Text* _playerWorldLv;
        struct Text* _playerBirthday;
        struct Text* _playerSignature;
        struct Text* _playerNoSignature;
        struct RectTransform* _playerSignatureRect;
        struct Image_1* _nameCardPic;
        struct Button_1* _closeButton;
        struct MonoElementSwitch* _elementSwitch;
        struct MihoyoGridLayoutGroup* _menuEntryLayout;
        struct MonoReusableList* _entryList;
        struct List_1_MoleMole_PaimonEntryConfig_* _entryConfigs;
        struct MonoUIContainer* _playerLevelBtn;
        struct Vector3 _offsetPos;
        float transDuration;
        float transLerpRatio;
        int32_t lerpPattern;
        struct MonoUIContainer* _photographBtn;
        struct MonoUIContainer* _bulletinBtn;
        struct MonoUIContainer* _mailBtn;
        struct MonoUIContainer* _timeBtn;
        struct MonoUIContainer* _settingBtn;
        struct Button_1* _iconBtn;
        struct MonoUIContainer* _editBtn;
        struct RectTransform* _editPanel;
        struct Button_1* _editReturnBtn;
        struct MonoUIContainer* _editHeadPortraitBtn;
        struct MonoUIContainer* _editNameCardBtn;
        struct MonoUIContainer* _editSignatureBtn;
        struct MonoUIContainer* _editNameBtn;
        struct MonoUIContainer* _editCopyUidBtn;
        struct MonoUIContainer* _editBirthdayBtn;
        struct MonoUIContainer* _editProfileBtn;
        struct MonoUIContainer* _worldLvInfoBtn;
        struct MonoUIContainer* _playerLvInfoBtn;
        struct Button_1* _copyBtn;
        struct RectTransform* _copyText;
        struct RectTransform* _ps4OnlineID;
        struct Text* _ps4OnlineIDText;
        struct GameObject* _upArrowIcon;
        struct GameObject* _downArrowIcon;
        float _redpointsCheckUpperOffset;
        float _redpointsCheckLowerOffset;
        struct String* _animStateAllowPaimonResponsePS5MicBlowEvent;
        float _thresholdDiscardPS5MicBlowEvent;
        float _thresholdPaimonResponsePS5MicBlowEventContinuely;
        struct MonoPS5MicBlowEventHandlerBase* _ps5MicBlowEventHandler;
    };

    struct MonoInLevelPlayerProfilePage {
        struct MonoInLevelPlayerProfilePage__Class* klass;
        MonitorData* monitor;
        struct MonoInLevelPlayerProfilePage__Fields fields;
    };

    struct MonoFriendInformationDialog__Fields {
        struct MonoUIProxy__Fields _;
        struct MonoElementSwitch* _elementSwitch;
        struct Text* _playerUID;
        struct Image_1* _icon;
        struct Text* _nickname;
        struct Text* _remarkname;
        struct Text* _playerLevel;
        struct Text* _worldLevel;
        struct Text* _signature;
        struct RectTransform* _signatureRect;
        struct Button_1* _returnBtn;
        struct MonoUIContainer* _ps4ID;
        struct RectTransform* _blockChatImg;
        struct RectTransform* _joypadBtnGroup;
        struct Image_1* _cardImg;
        struct Button_1* _signatureBtn;
        struct RectTransform* _editPanel;
        struct Button_1* _editReturnBtn;
        struct MonoGridScroller* _editScroller;
        struct Text* _achievementTxt;
        struct Text* _towerTxt;
        struct Text* _towerNoDataTxt;
        struct Text* _toggleTxt;
        struct GameObject* _iconHide;
        struct GameObject* _avatarEmptyGrp;
        struct GameObject* _toggleGrp;
        struct MonoGridScroller* _avatarScroller;
        struct MonoUIContainer* _toggle;
        struct MonoUIContainer* _mainPageBtn;
        struct GameObject* _achievementGrp;
        struct GameObject* _avatarGrp;
        struct MonoUIContainer* _nameCardBtn;
        struct GameObject* _nameCardGrp;
        struct MonoGridScroller* _nameCardScroller;
        struct GameObject* _nameCardEmptyGrp;
    };

    struct MonoFriendInformationDialog {
        struct MonoFriendInformationDialog__Class* klass;
        MonitorData* monitor;
        struct MonoFriendInformationDialog__Fields fields;
    };

    struct Color32 {
        int32_t rgba;
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    enum class PrimitiveType__Enum : int32_t {
        Sphere = 0x00000000,
        Capsule = 0x00000001,
        Cylinder = 0x00000002,
        Cube = 0x00000003,
        Plane = 0x00000004,
        Quad = 0x00000005,
    };

    enum class BrowserNative_ContextMenuOrigin__Enum : int32_t {
        Editable = 0x00000002,
        Image = 0x00000004,
        Selection = 0x00000008,
        Other = 0x00000001,
    };

    enum class Browser_NewWindowAction__Enum : int32_t {
        Ignore = 0x00000001,
        Redirect = 0x00000002,
        NewBrowser = 0x00000003,
        NewWindow = 0x00000004,
    };

    struct Browser__Fields {
        struct MonoBehaviour__Fields _;
        bool offScreen;
        struct IBrowserUI* _uiHandler;
        bool uiHandlerAssigned;
        struct String* _url;
        int32_t _width;
        int32_t _height;
        bool generateMipmap;
        struct Color32 baseColor;
        float _zoom;
        struct Action_2_String_String_* onConsoleMessage;
        BrowserNative_ContextMenuOrigin__Enum allowContextMenuOn;
        Browser_NewWindowAction__Enum newWindowAction;
        struct INewWindowHandler* _NewWindowHandler_k__BackingField;
        bool _EnableRendering_k__BackingField;
        bool _EnableInput_k__BackingField;
        struct CookieManager* _CookieManager_k__BackingField;
        int32_t browserId;
        int32_t unsafeBrowserId;
        bool browserIdRequested;
        struct Texture2D* texture;
        struct Action_1_UnityEngine_Texture2D_* afterResize;
        bool textureIsOurs;
        bool forceNextRender;
        bool isPopup;
        struct List_1_System_Action_* thingsToDo;
        struct List_1_System_Action_* onloadActions;
        struct List_1_System_Object_* thingsToRemember;
        int32_t nextCallbackId;
        struct Dictionary_2_System_Int32_ZenFulcrum_EmbeddedBrowser_Browser_JSResultFunc_* registeredCallbacks;
        struct BrowserNative_ReadyFunc* onNativeReady;
        struct Action_1_ZenFulcrum_EmbeddedBrowser_JSONNode_* onLoad;
        struct Action_1_ZenFulcrum_EmbeddedBrowser_JSONNode_* onFetch;
        struct Action_1_ZenFulcrum_EmbeddedBrowser_JSONNode_* onFetchError;
        struct Action_1_ZenFulcrum_EmbeddedBrowser_JSONNode_* onCertError;
        struct Action* onSadTab;
        struct Action* onTextureUpdated;
        struct Action* onNavStateChange;
        struct Action_2_Int32_ZenFulcrum_EmbeddedBrowser_JSONNode_* onDownloadStarted;
        struct Action_2_Int32_ZenFulcrum_EmbeddedBrowser_JSONNode_* onDownloadStatus;
        struct Action_3_String_Boolean_String_* onNodeFocus;
        struct Action_1_ZenFulcrum_EmbeddedBrowser_JSONNode_* onUniWebviewMsgReceive;
        struct Action_1_ZenFulcrum_EmbeddedBrowser_JSONNode_* onBeforeNavigationMsgReceive;
        struct Action_2_Boolean_Boolean_* onBrowserFocus;
        struct BrowserFocusState* focusState;
        struct BrowserInput* browserInput;
        struct Browser* overlay;
        bool skipNextLoad;
        bool loadPending;
        struct BrowserNavState* navState;
        bool newWindowHandlerSet;
        struct INewWindowHandler* newWindowHandler;
        struct DialogHandler* dialogHandler;
        struct Action* pageReplacer;
        float pageReplacerPriority;
        struct List_1_System_Action_* thingsToDoClone;
        struct Color32__Array* colorBuffer;
    };

    struct Browser {
        struct Browser__Class* klass;
        MonitorData* monitor;
        struct Browser__Fields fields;
    };

#if !defined(_GHIDRA_) && !defined(_IDA_)
}
#endif
