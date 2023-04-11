

#ifndef INC_ETHERNET_H_
#define INC_ETHERNET_H_

#include "main.h"

uint8_t get_econ1_register_value(void);
void switch_bank(uint8_t bank);
uint8_t read_control_register(uint16_t address);
uint8_t read_mac_mii_register(uint16_t address);
void set_recieve_buffer_by_percent(uint8_t percent);

#define CS_HIGH 	(GPIOB->ODR |= 1<<6)
#define CS_LOW		(GPIOB->ODR &= ~(1<<6))


/* ----- Bit masks and user defined constant register values ----- */


/* EIE REGISTER */
#define RXERIE		0U
#define TYREIE		1U
#define TXIE		3U
#define LINKIE		4U
#define DMAIE		5U
#define PKTIE		6U
#define INTIE		7U

/* EIR REGISTER */
#define RXERIF		0U
#define	TXERIF		1U
#define TXIF		3U
#define LINKIF		4U
#define DMAIF		5U
#define PKTIF		6U

/* ESTAT REGISTER */
#define CLKRDY		0
#define TXABRT		1
#define RXBUSY		2
#define LATECOL		4
#define BUFER		6
#define INT			7

/* ECON2 REGISTER */
#define VRPS		3
#define PWRSV		5
#define PKTDEC		6
#define AUTOINC		7

/* ECON1 REGISTER*/
#define BSEL0		0
#define BSEL1		1
#define RXEN		2
#define TXRTS		3
#define CSUMEN		4
#define DMAST		5
#define RXRST 		6
#define TXRST		7

//#define ERDPTL_DATA
//#define ERDPTH_DATA
//#define EWEPTL_DATA
//#define EWRPTH_DATA
//#define ETXSTL_DATA
//#define ETXSTH_DATA
//#define ETXNDL_DATA
//#define ETXNDH_DATA
#define ERXSTL_DATA 		0x00
#define ERXSTH_DATA			0x00
//#define ERXNDL_DATA
//#define ERXNDH_DATA
//#define ERXRDPTL_DATA
//#define ERXRDPTH_DATA
//#define ERXWRPTL_DATA
//#define ERXWRPTH_DATA
//#define EDMASTL_DATA
//#define EDMASTH_DATA
//#define EDMANDL_DATA
//#define EDMANDH_DATA
//#define EDMADSTL_DATA
//#define EDMADSTH_DATA
//#define EDMACSL_DATA
//#define EDMACSH_DATA
//#define EHT0_DATA
//#define EHT1_DATA
//#define EHT2_DATA
//#define EHT3_DATA
//#define EHT4_DATA
//#define EHT5_DATA
//#define EHT6_DATA
//#define EHT7_DATA
//#define EPMM0_DATA
//#define EPMM1_DATA
//#define EPMM2_DATA
//#define EPMM3_DATA
//#define EPMM4_DATA
//#define EPMM5_DATA
//#define EPMM6_DATA
//#define EPMM7_DATA
//#define EPMCSL_DATA
//#define EPMCSH_DATA
//#define EPMOL_DATA
//#define EPMOH_DATA

/* ERXFCON */
#define BCEN		0
#define MCEN		1
#define HTEN		2
#define MPEN		3
#define PMEN		4
#define CRCEN		5
#define ANDOR		6
#define UCEN		7

/* EPKTCNT */

/* MACON1 */
#define MARXEN		0
#define PASSALL		1
#define RXPAUS		2
#define TXPAUS		3

/* MACON3 */
#define FULDPX		0
#define FRMLNEN		1
#define HFRMEN		2
#define PHDREN		3
#define TXCRCEN		4
#define PADCFG0		5
#define PADCFG1		6
#define PADCFG2		7

/* MACON 4 */
#define NOBKOFF		4
#define BPEN		5
#define DEFER		6

//#define MABBIPG_DATA
//#define MAIPGL_DATA
//#define MAIPGH_DATA
//#define MACLCON1_DATA
//#define MACLCON2_DATA
//#define MAMXFLL_DATA
//#define MAMXFLH_DATA /

/* MICMD */
#define MIIRD		0
#define MIISCAN		1

//#define MIREGADR_DATA
//#define MIWRL_DATA
//#define MIWRH_DATA
//#define MIRDL_DATA
//#define MIRDH_DATA
//#define MAADR5_DATA
//#define MAADR6_DATA
//#define MAADR3_DATA
//#define MAADR4_DATA
//#define MAADR1_DATA
//#define MAADR2_DATA
//#define EBSTSD_DATA

/* EBSTCON */
#define BISTST		0
#define TME			1
#define TMSEL0		2
#define TMSEL1		3
#define PSEL		4
#define PSV0		5
#define PSV1		6
#define PSV2		7

//#define EBSTCSL_DATA
//#define EBSTCSH_DATA

/* MISTAT */
#define	BUSY		0
#define SCAN		1
#define NVALID		2

//#define EREVID_DATA

/* ECOCON */
#define COCON0		0
#define COCON1		1
#define COCON2		2

/* EFLOCON */
#define FCEN0		0
#define FCEN1		1
#define FULDPXS		2

//#define EPAUSL_DATA
//#define EPAUSH_DATA


/* ------ Opcode for registers ------ */

#define RCR			(0x00U)		// RCR - Read Control Register
#define WCR			(0x02U)		// WCR - Write Control Register

#define RBM			(0x01U)		// RBM - Read Buffer Register
#define RBM			(0x03U)		// WBM - Write Buffer Register

/* ----- BANKS ----- */

#define BANK0 		(0U)
#define BANK1		(1U)
#define BANK2		(2U)
#define BANK3		(3U)


/* ----- ETHERNET MODULE ADDRESSES ---- */

/* -- BANK0 -- */

#define ERDPTL			(0x0000U)
#define ERDPTH			(0x0001U)
#define EWRPTL			(0x0002U)
#define EWRPTH			(0x0003U)
#define ETXSTL			(0x0004U)
#define ETXSTH			(0x0005U)
#define ETXNDL			(0x0006U)
#define ETXNDH			(0x0007U)
#define ERXSTL			(0x0008U)
#define ERXSTH			(0x0009U)
#define ERXNDL			(0x000AU)
#define ERXNDH			(0x000BU)
#define ERXRDPTL		(0x000CU)
#define ERXRDPTH		(0x000DU)
#define ERXWRPTL		(0x000EU)
#define ERXWRPTH		(0x000FU)
#define EDMASTL			(0x0010U)
#define EDMASTH			(0x0011U)
#define EDMANDL			(0x0012U)
#define EDMANDH			(0x0013U)
#define EDMADSTL		(0x0014U)
#define EDMADSTH		(0x0015U)
#define EDMACSL			(0x0016U)
#define EDMACSH			(0x0017U)
#define 				(0x0018U)
#define 				(0x0019U)
#define RESERVED		(0x001AU)
#define EIE				(0x001BU)
#define EIR				(0x001CU)
#define ESTAT			(0x001DU)
#define ECON2			(0x001EU)
#define ECON1			(0x001FU)


/* -- BANK1 -- */

#define ETH0			(0x0100U)
#define ETH1			(0x0101U)
#define ETH2			(0x0102U)
#define ETH3			(0x0103U)
#define ETH4			(0x0104U)
#define ETH5			(0x0105U)
#define ETH6			(0x0106U)
#define ETH7			(0x0107U)
#define EPMM0			(0x0108U)
#define EPMM1			(0x0109U)
#define EPMM2			(0x010AU)
#define EPMM3			(0x010BU)
#define EPMM4			(0x010CU)
#define EPMM5			(0x010DU)
#define EPMM6			(0x010EU)
#define EPMM7			(0x010FU)
#define EPMCSL			(0x0110U)
#define EPMCSH			(0x0111U)
#define 				(0x0112U)
#define 				(0x0113U)
#define EPMOL			(0x0114U)
#define EPMOH			(0x0115U)
#define 				(0x0116U)
#define 				(0x0117U)
#define ERXFCON			(0x0118U)
#define EPKTCNT			(0x0119U)
#define 				(0x011AU)



/* -- BANK2 -- */

#define MACON1			(0x0200U)
#define 				(0x0201U)
#define MACON2			(0x0202U)
#define MACON3			(0x0203U)
#define MABBIPG			(0x0204U)
#define 				(0x0205U)
#define MAIPGL			(0x0206U)
#define MAIPGH			(0x0207U)
#define MACLCON1		(0x0208U)
#define MACLCON2		(0x0209U)
#define MAMXFLL			(0x020AU)
#define MAMXFLH			(0x020BU)
#define 				(0x020CU)
#define 				(0x020DU)
#define 				(0x020EU)
#define 				(0x020FU)
#define 				(0x0210U)
#define 				(0x0211U)
#define MICMD			(0x0212U)
#define 				(0x0213U)
#define MIREGADR		(0x0214U)
#define 				(0x0215U)
#define MIWRL			(0x0216U)
#define MIWRH			(0x0217U)
#define MIRDL			(0x0218U)
#define MIRDH			(0x0219U)
#define 				(0x021AU)


/* -- BANK3 -- */

#define MAADR5			(0x0300U)
#define MAADR6			(0x0301U)
#define MAADR3			(0x0302U)
#define MAADR4			(0x0303U)
#define MAADR1			(0x0304U)
#define MAADR2			(0x0305U)
#define EBSTSD			(0x0306U)
#define EBSTCON			(0x0307U)
#define EBSTCSL			(0x0308U)
#define EBSTCSH			(0x0309U)
#define MISTAT			(0x030AU)
#define 				(0x030BU)
#define 				(0x030CU)
#define 				(0x030DU)
#define 				(0x030EU)
#define 				(0x030FU)
#define 				(0x0310U)
#define 				(0x0311U)
#define EREVID			(0x0312U)
#define 				(0x0313U)
#define 				(0x0314U)
#define ECOCON			(0x0315U)
#define 				(0x0316U)
#define EFLOCON			(0x0317U)
#define EPAUSL			(0x0318U)
#define EPAUSH			(0x0319U)
#define 				(0x031AU)





#endif /* INC_ETHERNET_H_ */
