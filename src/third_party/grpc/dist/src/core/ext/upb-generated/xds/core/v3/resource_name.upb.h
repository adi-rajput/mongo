/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     xds/core/v3/resource_name.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef XDS_CORE_V3_RESOURCE_NAME_PROTO_UPB_H_
#define XDS_CORE_V3_RESOURCE_NAME_PROTO_UPB_H_

#include "upb/generated_code_support.h"
// Must be last. 
#include "upb/port/def.inc"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct xds_core_v3_ResourceName xds_core_v3_ResourceName;
extern const upb_MiniTable xds_core_v3_ResourceName_msg_init;
struct xds_core_v3_ContextParams;
extern const upb_MiniTable xds_core_v3_ContextParams_msg_init;



/* xds.core.v3.ResourceName */

UPB_INLINE xds_core_v3_ResourceName* xds_core_v3_ResourceName_new(upb_Arena* arena) {
  return (xds_core_v3_ResourceName*)_upb_Message_New(&xds_core_v3_ResourceName_msg_init, arena);
}
UPB_INLINE xds_core_v3_ResourceName* xds_core_v3_ResourceName_parse(const char* buf, size_t size, upb_Arena* arena) {
  xds_core_v3_ResourceName* ret = xds_core_v3_ResourceName_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &xds_core_v3_ResourceName_msg_init, NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE xds_core_v3_ResourceName* xds_core_v3_ResourceName_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  xds_core_v3_ResourceName* ret = xds_core_v3_ResourceName_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &xds_core_v3_ResourceName_msg_init, extreg, options, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* xds_core_v3_ResourceName_serialize(const xds_core_v3_ResourceName* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &xds_core_v3_ResourceName_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* xds_core_v3_ResourceName_serialize_ex(const xds_core_v3_ResourceName* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &xds_core_v3_ResourceName_msg_init, options, arena, &ptr, len);
  return ptr;
}
UPB_INLINE void xds_core_v3_ResourceName_clear_id(xds_core_v3_ResourceName* msg) {
  const upb_MiniTableField field = {1, 8, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView xds_core_v3_ResourceName_id(const xds_core_v3_ResourceName* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {1, 8, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE void xds_core_v3_ResourceName_clear_authority(xds_core_v3_ResourceName* msg) {
  const upb_MiniTableField field = {2, UPB_SIZE(16, 24), 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView xds_core_v3_ResourceName_authority(const xds_core_v3_ResourceName* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {2, UPB_SIZE(16, 24), 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE void xds_core_v3_ResourceName_clear_resource_type(xds_core_v3_ResourceName* msg) {
  const upb_MiniTableField field = {3, UPB_SIZE(24, 40), 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView xds_core_v3_ResourceName_resource_type(const xds_core_v3_ResourceName* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {3, UPB_SIZE(24, 40), 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE void xds_core_v3_ResourceName_clear_context(xds_core_v3_ResourceName* msg) {
  const upb_MiniTableField field = {4, UPB_SIZE(4, 56), 1, 0, 11, (int)kUpb_FieldMode_Scalar | ((int)UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE const struct xds_core_v3_ContextParams* xds_core_v3_ResourceName_context(const xds_core_v3_ResourceName* msg) {
  const struct xds_core_v3_ContextParams* default_val = NULL;
  const struct xds_core_v3_ContextParams* ret;
  const upb_MiniTableField field = {4, UPB_SIZE(4, 56), 1, 0, 11, (int)kUpb_FieldMode_Scalar | ((int)UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE bool xds_core_v3_ResourceName_has_context(const xds_core_v3_ResourceName* msg) {
  const upb_MiniTableField field = {4, UPB_SIZE(4, 56), 1, 0, 11, (int)kUpb_FieldMode_Scalar | ((int)UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  return _upb_Message_HasNonExtensionField(msg, &field);
}

UPB_INLINE void xds_core_v3_ResourceName_set_id(xds_core_v3_ResourceName *msg, upb_StringView value) {
  const upb_MiniTableField field = {1, 8, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void xds_core_v3_ResourceName_set_authority(xds_core_v3_ResourceName *msg, upb_StringView value) {
  const upb_MiniTableField field = {2, UPB_SIZE(16, 24), 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void xds_core_v3_ResourceName_set_resource_type(xds_core_v3_ResourceName *msg, upb_StringView value) {
  const upb_MiniTableField field = {3, UPB_SIZE(24, 40), 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void xds_core_v3_ResourceName_set_context(xds_core_v3_ResourceName *msg, struct xds_core_v3_ContextParams* value) {
  const upb_MiniTableField field = {4, UPB_SIZE(4, 56), 1, 0, 11, (int)kUpb_FieldMode_Scalar | ((int)UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE struct xds_core_v3_ContextParams* xds_core_v3_ResourceName_mutable_context(xds_core_v3_ResourceName* msg, upb_Arena* arena) {
  struct xds_core_v3_ContextParams* sub = (struct xds_core_v3_ContextParams*)xds_core_v3_ResourceName_context(msg);
  if (sub == NULL) {
    sub = (struct xds_core_v3_ContextParams*)_upb_Message_New(&xds_core_v3_ContextParams_msg_init, arena);
    if (sub) xds_core_v3_ResourceName_set_context(msg, sub);
  }
  return sub;
}

extern const upb_MiniTableFile xds_core_v3_resource_name_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif  /* XDS_CORE_V3_RESOURCE_NAME_PROTO_UPB_H_ */
