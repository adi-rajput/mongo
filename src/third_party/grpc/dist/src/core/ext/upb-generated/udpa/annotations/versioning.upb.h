/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     udpa/annotations/versioning.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef UDPA_ANNOTATIONS_VERSIONING_PROTO_UPB_H_
#define UDPA_ANNOTATIONS_VERSIONING_PROTO_UPB_H_

#include "upb/generated_code_support.h"
// Must be last. 
#include "upb/port/def.inc"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct udpa_annotations_VersioningAnnotation udpa_annotations_VersioningAnnotation;
extern const upb_MiniTable udpa_annotations_VersioningAnnotation_msg_init;
extern const upb_MiniTableExtension udpa_annotations_versioning_ext;
struct google_protobuf_MessageOptions;
extern const upb_MiniTable google_protobuf_MessageOptions_msg_init;



/* udpa.annotations.VersioningAnnotation */

UPB_INLINE udpa_annotations_VersioningAnnotation* udpa_annotations_VersioningAnnotation_new(upb_Arena* arena) {
  return (udpa_annotations_VersioningAnnotation*)_upb_Message_New(&udpa_annotations_VersioningAnnotation_msg_init, arena);
}
UPB_INLINE udpa_annotations_VersioningAnnotation* udpa_annotations_VersioningAnnotation_parse(const char* buf, size_t size, upb_Arena* arena) {
  udpa_annotations_VersioningAnnotation* ret = udpa_annotations_VersioningAnnotation_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &udpa_annotations_VersioningAnnotation_msg_init, NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE udpa_annotations_VersioningAnnotation* udpa_annotations_VersioningAnnotation_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  udpa_annotations_VersioningAnnotation* ret = udpa_annotations_VersioningAnnotation_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &udpa_annotations_VersioningAnnotation_msg_init, extreg, options, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* udpa_annotations_VersioningAnnotation_serialize(const udpa_annotations_VersioningAnnotation* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &udpa_annotations_VersioningAnnotation_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* udpa_annotations_VersioningAnnotation_serialize_ex(const udpa_annotations_VersioningAnnotation* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &udpa_annotations_VersioningAnnotation_msg_init, options, arena, &ptr, len);
  return ptr;
}
UPB_INLINE void udpa_annotations_VersioningAnnotation_clear_previous_message_type(udpa_annotations_VersioningAnnotation* msg) {
  const upb_MiniTableField field = {1, 0, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView udpa_annotations_VersioningAnnotation_previous_message_type(const udpa_annotations_VersioningAnnotation* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {1, 0, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}

UPB_INLINE void udpa_annotations_VersioningAnnotation_set_previous_message_type(udpa_annotations_VersioningAnnotation *msg, upb_StringView value) {
  const upb_MiniTableField field = {1, 0, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}

UPB_INLINE bool udpa_annotations_has_versioning(const struct google_protobuf_MessageOptions* msg) {
  return _upb_Message_HasExtensionField(msg, &udpa_annotations_versioning_ext);
}
UPB_INLINE void udpa_annotations_clear_versioning(struct google_protobuf_MessageOptions* msg) {
  _upb_Message_ClearExtensionField(msg, &udpa_annotations_versioning_ext);
}
UPB_INLINE const udpa_annotations_VersioningAnnotation* udpa_annotations_versioning(const struct google_protobuf_MessageOptions* msg) {
  const upb_MiniTableExtension* ext = &udpa_annotations_versioning_ext;
  UPB_ASSUME(!upb_IsRepeatedOrMap(&ext->field));
  UPB_ASSUME(_upb_MiniTableField_GetRep(&ext->field) == kUpb_FieldRep_8Byte);
  const udpa_annotations_VersioningAnnotation* default_val = NULL;
  const udpa_annotations_VersioningAnnotation* ret;
  _upb_Message_GetExtensionField(msg, ext, &default_val, &ret);
  return ret;
}
UPB_INLINE void udpa_annotations_set_versioning(struct google_protobuf_MessageOptions* msg, const udpa_annotations_VersioningAnnotation* val, upb_Arena* arena) {
  const upb_MiniTableExtension* ext = &udpa_annotations_versioning_ext;
  UPB_ASSUME(!upb_IsRepeatedOrMap(&ext->field));
  UPB_ASSUME(_upb_MiniTableField_GetRep(&ext->field) == kUpb_FieldRep_8Byte);
  bool ok = _upb_Message_SetExtensionField(msg, ext, &val, arena);
  UPB_ASSERT(ok);
}
extern const upb_MiniTableFile udpa_annotations_versioning_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif  /* UDPA_ANNOTATIONS_VERSIONING_PROTO_UPB_H_ */
