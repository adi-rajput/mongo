/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/annotations/resource.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/generated_code_support.h"
#include "envoy/annotations/resource.upb.h"
#include "google/protobuf/descriptor.upb.h"

// Must be last.
#include "upb/port/def.inc"

static const upb_MiniTableField envoy_annotations_ResourceAnnotation__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_annotations_ResourceAnnotation_msg_init = {
  NULL,
  &envoy_annotations_ResourceAnnotation__fields[0],
  UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f00000a, &upb_pss_1bt},
  })
};

static const upb_MiniTable *messages_layout[1] = {
  &envoy_annotations_ResourceAnnotation_msg_init,
};

extern const upb_MiniTable envoy_annotations_ResourceAnnotation_msg_init;
extern const upb_MiniTable google_protobuf_ServiceOptions_msg_init;
const upb_MiniTableExtension envoy_annotations_resource_ext = {
  {265073217, 0, 0, 0, 11, (int)kUpb_FieldMode_Scalar | (int)kUpb_LabelFlags_IsExtension | ((int)kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
  &google_protobuf_ServiceOptions_msg_init,
  {.submsg = &envoy_annotations_ResourceAnnotation_msg_init},

};

static const upb_MiniTableExtension *extensions_layout[1] = {
  &envoy_annotations_resource_ext,
};

const upb_MiniTableFile envoy_annotations_resource_proto_upb_file_layout = {
  messages_layout,
  NULL,
  extensions_layout,
  1,
  0,
  1,
};

#include "upb/port/undef.inc"

