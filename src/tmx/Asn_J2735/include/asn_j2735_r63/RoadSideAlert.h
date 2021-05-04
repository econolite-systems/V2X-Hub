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

#ifndef	_RoadSideAlert_H_
#define	_RoadSideAlert_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DSRC_MsgCount.h"
#include "MinuteOfTheYear.h"
#include "ITIScodes.h"
#include "Priority.h"
#include "HeadingSlice.h"
#include "Extent.h"
#include "FurtherInfoID.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct FullPositionVector;
struct Reg_BasicSafetyMessage;

/* RoadSideAlert */
typedef struct RoadSideAlert {
	DSRC_MsgCount_t	 msgCnt;
	MinuteOfTheYear_t	*timeStamp;	/* OPTIONAL */
	ITIScodes_t	 typeEvent;
	struct RoadSideAlert__description {
		A_SEQUENCE_OF(ITIScodes_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *description;
	Priority_t	*priority;	/* OPTIONAL */
	HeadingSlice_t	*heading;	/* OPTIONAL */
	Extent_t	*extent;	/* OPTIONAL */
	struct FullPositionVector	*position;	/* OPTIONAL */
	FurtherInfoID_t	*furtherInfoID;	/* OPTIONAL */
	struct RoadSideAlert__regional {
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
} RoadSideAlert_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RoadSideAlert;
extern asn_SEQUENCE_specifics_t asn_SPC_RoadSideAlert_specs_1;
extern asn_TYPE_member_t asn_MBR_RoadSideAlert_1[10];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "FullPositionVector.h"
#include "RegionalExtension.h"

#endif	/* _RoadSideAlert_H_ */
#include "asn_internal.h"
