/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
<<<<<<< HEAD
 * 	found in "J2735_201603_ASN_CC.asn"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted -fskeletons-copy`
=======
 * 	found in "J2735_201603.asn1"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted`
>>>>>>> develop
 */

#include "MovementPhaseState.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_MovementPhaseState_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_MovementPhaseState_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  9 }	/* (0..9) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_MovementPhaseState_value2enum_1[] = {
	{ 0,	11,	"unavailable" },
	{ 1,	4,	"dark" },
	{ 2,	17,	"stop-Then-Proceed" },
	{ 3,	15,	"stop-And-Remain" },
	{ 4,	12,	"pre-Movement" },
	{ 5,	27,	"permissive-Movement-Allowed" },
	{ 6,	26,	"protected-Movement-Allowed" },
	{ 7,	20,	"permissive-clearance" },
	{ 8,	19,	"protected-clearance" },
	{ 9,	27,	"caution-Conflicting-Traffic" }
};
static const unsigned int asn_MAP_MovementPhaseState_enum2value_1[] = {
	9,	/* caution-Conflicting-Traffic(9) */
	1,	/* dark(1) */
	5,	/* permissive-Movement-Allowed(5) */
	7,	/* permissive-clearance(7) */
	4,	/* pre-Movement(4) */
	6,	/* protected-Movement-Allowed(6) */
	8,	/* protected-clearance(8) */
	3,	/* stop-And-Remain(3) */
	2,	/* stop-Then-Proceed(2) */
	0	/* unavailable(0) */
};
const asn_INTEGER_specifics_t asn_SPC_MovementPhaseState_specs_1 = {
	asn_MAP_MovementPhaseState_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_MovementPhaseState_enum2value_1,	/* N => "tag"; sorted by N */
	10,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_MovementPhaseState_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_MovementPhaseState = {
	"MovementPhaseState",
	"MovementPhaseState",
	&asn_OP_NativeEnumerated,
	asn_DEF_MovementPhaseState_tags_1,
	sizeof(asn_DEF_MovementPhaseState_tags_1)
		/sizeof(asn_DEF_MovementPhaseState_tags_1[0]), /* 1 */
	asn_DEF_MovementPhaseState_tags_1,	/* Same as above */
	sizeof(asn_DEF_MovementPhaseState_tags_1)
		/sizeof(asn_DEF_MovementPhaseState_tags_1[0]), /* 1 */
	{ &asn_OER_type_MovementPhaseState_constr_1, &asn_PER_type_MovementPhaseState_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_MovementPhaseState_specs_1	/* Additional specs */
};

