/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     google/protobuf/wrappers.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/generated_code_support.h"
#include "google/protobuf/wrappers.upb.h"

// Must be last.
#include "upb/port/def.inc"

static const upb_MiniTableField google_protobuf_DoubleValue__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 1, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_DoubleValue_msg_init = {
  NULL,
  &google_protobuf_DoubleValue__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f000009, &upb_psf8_1bt},
  })
};

static const upb_MiniTableField google_protobuf_FloatValue__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 2, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_FloatValue_msg_init = {
  NULL,
  &google_protobuf_FloatValue__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f00000d, &upb_psf4_1bt},
  })
};

static const upb_MiniTableField google_protobuf_Int64Value__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 3, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_Int64Value_msg_init = {
  NULL,
  &google_protobuf_Int64Value__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f000008, &upb_psv8_1bt},
  })
};

static const upb_MiniTableField google_protobuf_UInt64Value__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 4, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_8Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_UInt64Value_msg_init = {
  NULL,
  &google_protobuf_UInt64Value__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f000008, &upb_psv8_1bt},
  })
};

static const upb_MiniTableField google_protobuf_Int32Value__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 5, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_Int32Value_msg_init = {
  NULL,
  &google_protobuf_Int32Value__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f000008, &upb_psv4_1bt},
  })
};

static const upb_MiniTableField google_protobuf_UInt32Value__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 13, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_4Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_UInt32Value_msg_init = {
  NULL,
  &google_protobuf_UInt32Value__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f000008, &upb_psv4_1bt},
  })
};

static const upb_MiniTableField google_protobuf_BoolValue__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 8, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_BoolValue_msg_init = {
  NULL,
  &google_protobuf_BoolValue__fields[0],
  8, 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f000008, &upb_psb1_1bt},
  })
};

static const upb_MiniTableField google_protobuf_StringValue__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 9, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_StringValue_msg_init = {
  NULL,
  &google_protobuf_StringValue__fields[0],
  UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f00000a, &upb_pss_1bt},
  })
};

static const upb_MiniTableField google_protobuf_BytesValue__fields[1] = {
  {1, 0, 0, kUpb_NoSub, 12, (int)kUpb_FieldMode_Scalar | ((int)kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
};

const upb_MiniTable google_protobuf_BytesValue_msg_init = {
  NULL,
  &google_protobuf_BytesValue__fields[0],
  UPB_SIZE(8, 16), 1, kUpb_ExtMode_NonExtendable, 1, UPB_FASTTABLE_MASK(8), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000000003f00000a, &upb_psb_1bt},
  })
};

static const upb_MiniTable *messages_layout[9] = {
  &google_protobuf_DoubleValue_msg_init,
  &google_protobuf_FloatValue_msg_init,
  &google_protobuf_Int64Value_msg_init,
  &google_protobuf_UInt64Value_msg_init,
  &google_protobuf_Int32Value_msg_init,
  &google_protobuf_UInt32Value_msg_init,
  &google_protobuf_BoolValue_msg_init,
  &google_protobuf_StringValue_msg_init,
  &google_protobuf_BytesValue_msg_init,
};

const upb_MiniTableFile google_protobuf_wrappers_proto_upb_file_layout = {
  messages_layout,
  NULL,
  NULL,
  9,
  0,
  0,
};

#include "upb/port/undef.inc"

