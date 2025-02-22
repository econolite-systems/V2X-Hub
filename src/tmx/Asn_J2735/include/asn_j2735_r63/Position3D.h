/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "J2735_201603_ASN_CC.asn"
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted -fskeletons-copy`
 */

#ifndef	_Position3D_H_
#define	_Position3D_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Latitude.h"
#include "Longitude.h"
#include "DSRC_Elevation.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Reg_BasicSafetyMessage;

/* Position3D */
typedef struct Position3D {
	Latitude_t	 lat;
	Longitude_t	 Long;
	DSRC_Elevation_t	*elevation;	/* OPTIONAL */
	struct Position3D__regional {
		A_SEQUENCE_OF(struct Reg_BasicSafetyMessage) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *regional;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Position3D_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Position3D;
extern asn_SEQUENCE_specifics_t asn_SPC_Position3D_specs_1;
extern asn_TYPE_member_t asn_MBR_Position3D_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _Position3D_H_ */
#include "asn_internal.h"
