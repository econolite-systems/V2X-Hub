/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
<<<<<<< HEAD
 * 	found in "J2735_201603_ASN_CC.asn"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted -fskeletons-copy`
=======
 * 	found in "J2735_201603.asn1"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted`
>>>>>>> develop
 */

#ifndef	_Altitude_H_
#define	_Altitude_H_


#include "asn_application.h"

/* Including external dependencies */
#include "AltitudeValue.h"
#include "AltitudeConfidence.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Altitude */
typedef struct Altitude {
	AltitudeValue_t	 value;
	AltitudeConfidence_t	 confidence;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Altitude_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Altitude;
extern asn_SEQUENCE_specifics_t asn_SPC_Altitude_specs_1;
extern asn_TYPE_member_t asn_MBR_Altitude_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Altitude_H_ */
#include "asn_internal.h"
