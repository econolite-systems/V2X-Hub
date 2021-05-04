/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpB"
<<<<<<< HEAD
 * 	found in "J2735_201603_ASN_CC.asn"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted -fskeletons-copy`
=======
 * 	found in "J2735_201603.asn1"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted`
>>>>>>> develop
 */

#include "MinutesAngle.h"

int
MinutesAngle_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 59)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using NativeInteger,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_MinutesAngle_constr_1 CC_NOTUSED = {
	{ 1, 1 }	/* (0..59) */,
	-1};
asn_per_constraints_t asn_PER_type_MinutesAngle_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 6,  6,  0,  59 }	/* (0..59) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const ber_tlv_tag_t asn_DEF_MinutesAngle_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_MinutesAngle = {
	"MinutesAngle",
	"MinutesAngle",
	&asn_OP_NativeInteger,
	asn_DEF_MinutesAngle_tags_1,
	sizeof(asn_DEF_MinutesAngle_tags_1)
		/sizeof(asn_DEF_MinutesAngle_tags_1[0]), /* 1 */
	asn_DEF_MinutesAngle_tags_1,	/* Same as above */
	sizeof(asn_DEF_MinutesAngle_tags_1)
		/sizeof(asn_DEF_MinutesAngle_tags_1[0]), /* 1 */
	{ &asn_OER_type_MinutesAngle_constr_1, &asn_PER_type_MinutesAngle_constr_1, MinutesAngle_constraint },
	0, 0,	/* No members */
	0	/* No specifics */
};

