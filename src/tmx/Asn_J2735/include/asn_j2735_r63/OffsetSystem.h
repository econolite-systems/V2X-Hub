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

#ifndef	_OffsetSystem_H_
#define	_OffsetSystem_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Zoom.h"
#include "NodeListXY.h"
#include "NodeListLL.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum OffsetSystem__offset_PR {
	OffsetSystem__offset_PR_NOTHING,	/* No components present */
	OffsetSystem__offset_PR_xy,
	OffsetSystem__offset_PR_ll
} OffsetSystem__offset_PR;

/* OffsetSystem */
typedef struct OffsetSystem {
	Zoom_t	*scale;	/* OPTIONAL */
	struct OffsetSystem__offset {
		OffsetSystem__offset_PR present;
		union OffsetSystem__offset_u {
			NodeListXY_t	 xy;
			NodeListLL_t	 ll;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} offset;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} OffsetSystem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_OffsetSystem;
extern asn_SEQUENCE_specifics_t asn_SPC_OffsetSystem_specs_1;
extern asn_TYPE_member_t asn_MBR_OffsetSystem_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _OffsetSystem_H_ */
#include "asn_internal.h"
