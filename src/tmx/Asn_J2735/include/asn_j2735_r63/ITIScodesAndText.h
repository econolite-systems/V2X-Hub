/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITIS"
<<<<<<< HEAD
 * 	found in "J2735_201603_ASN_CC.asn"
=======
 * 	found in "J2735_201603.asn1"
>>>>>>> develop
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted`
 */

#ifndef	_ITIScodesAndText_H_
#define	_ITIScodesAndText_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "ITIScodes.h"
#include "ITIStext.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ITIScodesAndText__Member__item_PR {
	ITIScodesAndText__Member__item_PR_NOTHING,	/* No components present */
	ITIScodesAndText__Member__item_PR_itis,
	ITIScodesAndText__Member__item_PR_text
} ITIScodesAndText__Member__item_PR;

/* Forward definitions */
typedef struct ITIScodesAndText__Member {
	struct ITIScodesAndText__Member__item {
		ITIScodesAndText__Member__item_PR present;
		union ITIScodesAndText__Member__item_u {
			ITIScodes_t	 itis;
			ITIStext_t	 text;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} item;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ITIScodesAndText__Member;

/* ITIScodesAndText */
typedef struct ITIScodesAndText {
	A_SEQUENCE_OF(ITIScodesAndText__Member) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ITIScodesAndText_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ITIScodesAndText;
extern asn_SET_OF_specifics_t asn_SPC_ITIScodesAndText_specs_1;
extern asn_TYPE_member_t asn_MBR_ITIScodesAndText_1[1];
extern asn_per_constraints_t asn_PER_type_ITIScodesAndText_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _ITIScodesAndText_H_ */
#include "asn_internal.h"
