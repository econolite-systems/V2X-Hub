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

#ifndef	_TestMessage02_H_
#define	_TestMessage02_H_


#include "asn_application.h"

/* Including external dependencies */
#include "MobilityHeader.h"
#include "MobilityPath.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

<<<<<<< HEAD
/* Forward declarations */
struct Header;
struct Reg_BasicSafetyMessage;

/* TestMessage02 */
typedef struct TestMessage02 {
	struct Header	*header;	/* OPTIONAL */
	struct Reg_BasicSafetyMessage	*regional;	/* OPTIONAL */
=======
/* TestMessage02 */
typedef struct TestMessage02 {
	MobilityHeader_t	 header;
	MobilityPath_t	 body;
>>>>>>> develop
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TestMessage02_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TestMessage02;
extern asn_SEQUENCE_specifics_t asn_SPC_TestMessage02_specs_1;
extern asn_TYPE_member_t asn_MBR_TestMessage02_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _TestMessage02_H_ */
#include "asn_internal.h"
