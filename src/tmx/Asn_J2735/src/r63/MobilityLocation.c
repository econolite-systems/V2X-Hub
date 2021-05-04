/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "J2735_201603.asn1"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted`
 */

#include "MobilityLocation.h"

asn_TYPE_member_t asn_MBR_MobilityLocation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MobilityLocation, ecefX),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MobilityECEFCoordinate,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ecefX"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MobilityLocation, ecefY),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MobilityECEFCoordinate,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ecefY"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MobilityLocation, ecefZ),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MobilityECEFCoordinate,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ecefZ"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MobilityLocation, timestamp),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MobilityTimestamp,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"timestamp"
		},
};
static const ber_tlv_tag_t asn_DEF_MobilityLocation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_MobilityLocation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ecefX */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ecefY */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ecefZ */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* timestamp */
};
asn_SEQUENCE_specifics_t asn_SPC_MobilityLocation_specs_1 = {
	sizeof(struct MobilityLocation),
	offsetof(struct MobilityLocation, _asn_ctx),
	asn_MAP_MobilityLocation_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_MobilityLocation = {
	"MobilityLocation",
	"MobilityLocation",
	&asn_OP_SEQUENCE,
	asn_DEF_MobilityLocation_tags_1,
	sizeof(asn_DEF_MobilityLocation_tags_1)
		/sizeof(asn_DEF_MobilityLocation_tags_1[0]), /* 1 */
	asn_DEF_MobilityLocation_tags_1,	/* Same as above */
	sizeof(asn_DEF_MobilityLocation_tags_1)
		/sizeof(asn_DEF_MobilityLocation_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_MobilityLocation_1,
	4,	/* Elements count */
	&asn_SPC_MobilityLocation_specs_1	/* Additional specs */
};

