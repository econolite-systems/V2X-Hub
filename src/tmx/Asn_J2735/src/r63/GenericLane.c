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

#include "GenericLane.h"

static int
memb_regional_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 4)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_regional_constr_11 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
static asn_per_constraints_t asn_PER_type_regional_constr_11 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_regional_constr_11 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
static asn_per_constraints_t asn_PER_memb_regional_constr_11 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_regional_11[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
<<<<<<< HEAD
		&asn_DEF_Reg_BasicSafetyMessage,
=======
		&asn_DEF_RegionalExtension_99P0,
>>>>>>> develop
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_regional_tags_11[] = {
	(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_regional_specs_11 = {
	sizeof(struct GenericLane__regional),
	offsetof(struct GenericLane__regional, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_regional_11 = {
	"regional",
	"regional",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_regional_tags_11,
	sizeof(asn_DEF_regional_tags_11)
		/sizeof(asn_DEF_regional_tags_11[0]) - 1, /* 1 */
	asn_DEF_regional_tags_11,	/* Same as above */
	sizeof(asn_DEF_regional_tags_11)
		/sizeof(asn_DEF_regional_tags_11[0]), /* 2 */
	{ &asn_OER_type_regional_constr_11, &asn_PER_type_regional_constr_11, SEQUENCE_OF_constraint },
	asn_MBR_regional_11,
	1,	/* Single element */
	&asn_SPC_regional_specs_11	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_GenericLane_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GenericLane, laneID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"laneID"
		},
	{ ATF_POINTER, 3, offsetof(struct GenericLane, name),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DescriptiveName,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"name"
		},
	{ ATF_POINTER, 2, offsetof(struct GenericLane, ingressApproach),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ApproachID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ingressApproach"
		},
	{ ATF_POINTER, 1, offsetof(struct GenericLane, egressApproach),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ApproachID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"egressApproach"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GenericLane, laneAttributes),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneAttributes,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"laneAttributes"
		},
	{ ATF_POINTER, 1, offsetof(struct GenericLane, maneuvers),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AllowedManeuvers,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"maneuvers"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GenericLane, nodeList),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NodeListXY,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nodeList"
		},
	{ ATF_POINTER, 3, offsetof(struct GenericLane, connectsTo),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ConnectsToList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"connectsTo"
		},
	{ ATF_POINTER, 2, offsetof(struct GenericLane, overlays),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OverlayLaneList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"overlays"
		},
	{ ATF_POINTER, 1, offsetof(struct GenericLane, regional),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		0,
		&asn_DEF_regional_11,
		0,
		{ &asn_OER_memb_regional_constr_11, &asn_PER_memb_regional_constr_11,  memb_regional_constraint_1 },
		0, 0, /* No default value */
		"regional"
		},
};
static const int asn_MAP_GenericLane_oms_1[] = { 1, 2, 3, 5, 7, 8, 9 };
static const ber_tlv_tag_t asn_DEF_GenericLane_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GenericLane_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* laneID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* name */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ingressApproach */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* egressApproach */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* laneAttributes */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* maneuvers */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* nodeList */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* connectsTo */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* overlays */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* regional */
};
asn_SEQUENCE_specifics_t asn_SPC_GenericLane_specs_1 = {
	sizeof(struct GenericLane),
	offsetof(struct GenericLane, _asn_ctx),
	asn_MAP_GenericLane_tag2el_1,
	10,	/* Count of tags in the map */
	asn_MAP_GenericLane_oms_1,	/* Optional members */
	7, 0,	/* Root/Additions */
	10,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GenericLane = {
	"GenericLane",
	"GenericLane",
	&asn_OP_SEQUENCE,
	asn_DEF_GenericLane_tags_1,
	sizeof(asn_DEF_GenericLane_tags_1)
		/sizeof(asn_DEF_GenericLane_tags_1[0]), /* 1 */
	asn_DEF_GenericLane_tags_1,	/* Same as above */
	sizeof(asn_DEF_GenericLane_tags_1)
		/sizeof(asn_DEF_GenericLane_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_GenericLane_1,
	10,	/* Elements count */
	&asn_SPC_GenericLane_specs_1	/* Additional specs */
};

