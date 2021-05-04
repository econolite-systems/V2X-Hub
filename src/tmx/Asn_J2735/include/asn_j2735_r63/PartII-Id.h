/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
<<<<<<< HEAD
 * 	found in "J2735_201603_ASN_CC.asn"
=======
 * 	found in "J2735_201603.asn1"
>>>>>>> develop
 * 	`asn1c -gen-PER -fcompound-names -fincludes-quoted`
 */

#ifndef	_PartII_Id_H_
#define	_PartII_Id_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PartII-Id */
typedef long	 PartII_Id_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PartII_Id_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PartII_Id;
asn_struct_free_f PartII_Id_free;
asn_struct_print_f PartII_Id_print;
asn_constr_check_f PartII_Id_constraint;
ber_type_decoder_f PartII_Id_decode_ber;
der_type_encoder_f PartII_Id_encode_der;
xer_type_decoder_f PartII_Id_decode_xer;
xer_type_encoder_f PartII_Id_encode_xer;
oer_type_decoder_f PartII_Id_decode_oer;
oer_type_encoder_f PartII_Id_encode_oer;
per_type_decoder_f PartII_Id_decode_uper;
per_type_encoder_f PartII_Id_encode_uper;
per_type_decoder_f PartII_Id_decode_aper;
per_type_encoder_f PartII_Id_encode_aper;
#define PartII_Id_vehicleSafetyExt	((PartII_Id_t)0)
#define PartII_Id_specialVehicleExt	((PartII_Id_t)1)
#define PartII_Id_supplementalVehicleExt	((PartII_Id_t)2)

#ifdef __cplusplus
}
#endif

#endif	/* _PartII_Id_H_ */
#include "asn_internal.h"
