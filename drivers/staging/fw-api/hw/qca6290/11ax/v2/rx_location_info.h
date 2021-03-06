/*
 * Copyright (c) 2016-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _RX_LOCATION_INFO_H_
#define _RX_LOCATION_INFO_H_
#if !defined(__ASSEMBLER__)
#endif


// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	rtt_fac_legacy[15:0], rtt_fac_legacy_ext80[31:16]
//	1	rtt_fac_vht[15:0], rtt_fac_vht_ext80[31:16]
//	2	rtt_fac_legacy_status[0], rtt_fac_legacy_ext80_status[1], rtt_fac_vht_status[2], rtt_fac_vht_ext80_status[3], rtt_fac_sifs[15:4], rtt_fac_sifs_status[17:16], rtt_cfr_status[18], rtt_cir_status[19], rtt_channel_dump_size[30:20], rtt_hw_ifft_mode[31]
//	3	rtt_btcf_status[0], rtt_preamble_type[5:1], rtt_pkt_bw_leg[7:6], rtt_pkt_bw_vht[9:8], rtt_gi_type[11:10], rtt_mcs_rate[16:12], rtt_strongest_chain[19:17], rtt_strongest_chain_ext80[22:20], rtt_rx_chain_mask[30:23], reserved_3[31]
//	4	rx_start_ts[31:0]
//	5	rx_end_ts[31:0]
//	6	sfo_phase_pkt_start[11:0], sfo_phase_pkt_end[23:12], rtt_che_buffer_pointer_high8[31:24]
//	7	rtt_che_buffer_pointer_low32[31:0]
//	8	rtt_cfo_measurement[13:0], rtt_chan_spread[21:14], rtt_timing_backoff_sel[23:22], reserved_8[30:24], rx_location_info_valid[31]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_LOCATION_INFO 9

struct rx_location_info {
             uint32_t rtt_fac_legacy                  : 16, //[15:0]
                      rtt_fac_legacy_ext80            : 16; //[31:16]
             uint32_t rtt_fac_vht                     : 16, //[15:0]
                      rtt_fac_vht_ext80               : 16; //[31:16]
             uint32_t rtt_fac_legacy_status           :  1, //[0]
                      rtt_fac_legacy_ext80_status     :  1, //[1]
                      rtt_fac_vht_status              :  1, //[2]
                      rtt_fac_vht_ext80_status        :  1, //[3]
                      rtt_fac_sifs                    : 12, //[15:4]
                      rtt_fac_sifs_status             :  2, //[17:16]
                      rtt_cfr_status                  :  1, //[18]
                      rtt_cir_status                  :  1, //[19]
                      rtt_channel_dump_size           : 11, //[30:20]
                      rtt_hw_ifft_mode                :  1; //[31]
             uint32_t rtt_btcf_status                 :  1, //[0]
                      rtt_preamble_type               :  5, //[5:1]
                      rtt_pkt_bw_leg                  :  2, //[7:6]
                      rtt_pkt_bw_vht                  :  2, //[9:8]
                      rtt_gi_type                     :  2, //[11:10]
                      rtt_mcs_rate                    :  5, //[16:12]
                      rtt_strongest_chain             :  3, //[19:17]
                      rtt_strongest_chain_ext80       :  3, //[22:20]
                      rtt_rx_chain_mask               :  8, //[30:23]
                      reserved_3                      :  1; //[31]
             uint32_t rx_start_ts                     : 32; //[31:0]
             uint32_t rx_end_ts                       : 32; //[31:0]
             uint32_t sfo_phase_pkt_start             : 12, //[11:0]
                      sfo_phase_pkt_end               : 12, //[23:12]
                      rtt_che_buffer_pointer_high8    :  8; //[31:24]
             uint32_t rtt_che_buffer_pointer_low32    : 32; //[31:0]
             uint32_t rtt_cfo_measurement             : 14, //[13:0]
                      rtt_chan_spread                 :  8, //[21:14]
                      rtt_timing_backoff_sel          :  2, //[23:22]
                      reserved_8                      :  7, //[30:24]
                      rx_location_info_valid          :  1; //[31]
};

/*

rtt_fac_legacy
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from L-LTF on the first selected
			Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from L-LTF on pri80 on the
			selected pri80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover pri80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>

rtt_fac_legacy_ext80
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from L-LTF on the second selected
			Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from L-LTF on ext80 on the
			selected ext80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover ext80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>

rtt_fac_vht
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on the first
			selected Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on pri80 on the
			selected pri80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover pri80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>

rtt_fac_vht_ext80
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on the second
			selected Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on ext80 on the
			selected ext80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover ext80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>

rtt_fac_legacy_status
			
			Status of rtt_fac_legacy
			
			
			
			<enum 0 location_fac_legacy_status_not_valid>
			
			<enum 1 location_fac_legacy_status_valid>
			
			<legal all>

rtt_fac_legacy_ext80_status
			
			Status of rtt_fac_legacy_ext80
			
			
			
			<enum 0 location_fac_legacy_ext80_status_not_valid>
			
			<enum 1 location_fac_legacy_ext80_status_valid>
			
			<legal all>

rtt_fac_vht_status
			
			Status of rtt_fac_vht
			
			
			
			<enum 0 location_fac_vht_status_not_valid>
			
			<enum 1 location_fac_vht_status_valid>
			
			<legal all>

rtt_fac_vht_ext80_status
			
			Status of rtt_fac_vht_ext80
			
			
			
			<enum 0 location_fac_vht_ext80_status_not_valid>
			
			<enum 1 location_fac_vht_ext80_status_valid>
			
			<legal all>

rtt_fac_sifs
			
			To support fine SIFS adjustment, need to provide FAC
			value @ integer number of 320 MHz clock cycles to MAC.?? It
			is from L-LTF if it is a Legacy packet and from (V)HT/HE-LTF
			if it is a (V)HT/HE packet
			
			
			
			12 bits, signed, no fractional part
			
			<legal all>

rtt_fac_sifs_status
			
			Status of rtt_fac_sifs
			
			0: not valid
			
			1: valid and from L-LTF
			
			2: valid and from (V)HT/HE-LTF
			
			3: reserved
			
			<legal 0-2>

rtt_cfr_status
			
			Status of channel frequency response dump
			
			
			
			<enum 0 location_CFR_dump_not_valid>
			
			<enum 1 location_CFR_dump_valid>
			
			<legal all>

rtt_cir_status
			
			Status of channel impulse response dump
			
			
			
			<enum 0 location_CIR_dump_not_valid>
			
			<enum 1 location_CIR_dump_valid>
			
			<legal all>

rtt_channel_dump_size
			
			Channel dump size.?? It shows how many tones in CFR in
			one chain, for example, it will show 52 for Legacy20 and 484
			for VHT160
			
			
			
			<legal all>

rtt_hw_ifft_mode
			
			Indicator showing if HW IFFT mode or SW IFFT mode
			
			
			
			<enum 0 location_sw_ifft_mode>
			
			<enum 1 location_hw_ifft_mode>
			
			<legal all>

rtt_btcf_status
			
			Indicate if BTCF is used to capture the timestamps
			
			
			
			<enum 0 location_not_BTCF_based_ts>
			
			<enum 1 location_BTCF_based_ts>
			
			<legal all>

rtt_preamble_type
			
			Indicate preamble type
			
			
			
			<enum 0 location_preamble_type_legacy>
			
			<enum 1 location_preamble_type_ht>
			
			<enum 2 location_preamble_type_vht>
			
			<enum 3 location_preamble_type_he_su_4xltf>
			
			<enum 4 location_preamble_type_he_su_2xltf>
			
			<enum 5 location_preamble_type_he_su_1xltf>
			
			<enum 6
			location_preamble_type_he_trigger_based_ul_4xltf>
			
			<enum 7
			location_preamble_type_he_trigger_based_ul_2xltf>
			
			<enum 8
			location_preamble_type_he_trigger_based_ul_1xltf>
			
			<enum 9 location_preamble_type_he_mu_4xltf>
			
			<enum 10 location_preamble_type_he_mu_2xltf>
			
			<enum 11 location_preamble_type_he_mu_1xltf>
			
			<enum 12
			location_preamble_type_he_extended_range_su_4xltf>
			
			<enum 13
			location_preamble_type_he_extended_range_su_2xltf>
			
			<enum 14
			location_preamble_type_he_extended_range_su_1xltf>
			
			<legal 0-14>

rtt_pkt_bw_leg
			
			Indicate the bandwidth of L-LTF
			
			
			
			<enum 0 location_pkt_bw_20MHz>
			
			<enum 1 location_pkt_bw_40MHz>
			
			<enum 2 location_pkt_bw_80MHz>
			
			<enum 3 location_pkt_bw_160MHz>
			
			<legal all>

rtt_pkt_bw_vht
			
			Indicate the bandwidth of (V)HT/HE-LTF
			
			
			
			<enum 0 location_pkt_bw_20MHz>
			
			<enum 1 location_pkt_bw_40MHz>
			
			<enum 2 location_pkt_bw_80MHz>
			
			<enum 3 location_pkt_bw_160MHz>
			
			<legal all>

rtt_gi_type
			
			Indicate GI (guard interval) type
			
			
			
			<enum 0     gi_0_8_us > HE related GI. Can also be used
			for HE
			
			<enum 1     gi_0_4_us > HE related GI. Can also be used
			for HE
			
			<enum 2     gi_1_6_us > HE related GI
			
			<enum 3     gi_3_2_us > HE related GI
			
			<legal 0 - 3>

rtt_mcs_rate
			
			Bits 0~4 indicate MCS rate, if Legacy, 
			
			0: 48 Mbps,
			
			1: 24 Mbps,
			
			2: 12 Mbps,
			
			3: 6 Mbps,
			
			4: 54 Mbps,
			
			5: 36 Mbps,
			
			6: 18 Mbps,
			
			7: 9 Mbps,
			
			
			
			if HT, 0-7: MCS0-MCS7, 
			
			if VHT, 0-9: MCS0-MCS9, 
			
			
			<legal all>

rtt_strongest_chain
			
			For 20/40/80, this field shows the first selected Rx
			chain that is used in HW IFFT mode
			
			
			
			For 80+80, this field shows the selected pri80 Rx chain
			that is used in HW IFFT mode
			
			
			
			<enum 0 location_strongest_chain_is_0>
			
			<enum 1 location_strongest_chain_is_1>
			
			<enum 2 location_strongest_chain_is_2>
			
			<enum 3 location_strongest_chain_is_3>
			
			<enum 4 location_strongest_chain_is_4>
			
			<enum 5 location_strongest_chain_is_5>
			
			<enum 6 location_strongest_chain_is_6>
			
			<enum 7 location_strongest_chain_is_7>
			
			<legal all>

rtt_strongest_chain_ext80
			
			For 20/40/80, this field shows the second selected Rx
			chain that is used in HW IFFT mode
			
			
			
			For 80+80, this field shows the selected ext80 Rx chain
			that is used in HW IFFT mode
			
			
			
			<enum 0 location_strongest_chain_is_0>
			
			<enum 1 location_strongest_chain_is_1>
			
			<enum 2 location_strongest_chain_is_2>
			
			<enum 3 location_strongest_chain_is_3>
			
			<enum 4 location_strongest_chain_is_4>
			
			<enum 5 location_strongest_chain_is_5>
			
			<enum 6 location_strongest_chain_is_6>
			
			<enum 7 location_strongest_chain_is_7>
			
			<legal all>

rtt_rx_chain_mask
			
			Rx chain mask, each bit is a Rx chain
			
			0: the Rx chain is not used
			
			1: the Rx chain is used
			
			Support up to 8 Rx chains
			
			<legal all>

reserved_3
			
			<legal 0>

rx_start_ts
			
			RX packet start timestamp
			
			
			
			It reports the time the first L-STF ADC sample arrived
			at RX antenna
			
			
			
			clock unit is 480MHz
			
			<legal all>

rx_end_ts
			
			RX packet end timestamp
			
			
			
			It reports the time the last symbol's last ADC sample
			arrived at RX antenna
			
			
			
			clock unit is 480MHz
			
			<legal all>

sfo_phase_pkt_start
			
			The phase of the SFO of the first symbol's first FFT
			input sample
			
			
			
			12 bits, signed 6.6. 6 bits integer to cover -66.7ns to
			66.7ns, and 6 bits fraction to provide a resolution of
			0.03ns
			
			
			
			clock unit is 480MHz
			
			<legal all>

sfo_phase_pkt_end
			
			The phase of the SFO of the last symbol's last FFT input
			sample
			
			
			
			12 bits, signed 6.6. 6 bits integer to cover -66.7ns to
			66.7ns, and 6 bits fraction to provide a resolution of
			0.03ns
			
			
			
			clock unit is 480MHz
			
			<legal all>

rtt_che_buffer_pointer_high8
			
			The high 8 bits of the 40 bits pointer pointed to the
			external RTT channel information buffer
			
			
			
			8 bits
			
			<legal all>

rtt_che_buffer_pointer_low32
			
			The low 32 bits of the 40 bits pointer pointed to the
			external RTT channel information buffer
			
			
			
			32 bits
			
			<legal all>

rtt_cfo_measurement
			
			CFO measurement. Needed for passive locationing
			
			
			
			14 bits, signed 1.13. 13 bits fraction to provide a
			resolution of 153 Hz
			
			
			
			In units of cycles/800 ns
			
			<legal all>

rtt_chan_spread
			
			Channel delay spread measurement. Needed for selecting
			GI length
			
			
			
			8 bits, unsigned. At 25 ns step. Can represent up to
			6375 ns
			
			
			
			In units of cycles @ 40 MHz
			
			<legal all>

rtt_timing_backoff_sel
			
			Indicate which timing backoff value is used
			
			
			
			<enum 0 timing_backoff_low_rssi>
			
			<enum 1 timing_backoff_mid_rssi>
			
			<enum 2 timing_backoff_high_rssi>
			
			<enum 3 reserved>
			
			<legal all>

reserved_8
			
			<legal 0>

rx_location_info_valid
			
			<enum 0 rx_location_info_is_not_valid>
			
			<enum 1 rx_location_info_is_valid>
			
			<legal all>
*/


/* Description		RX_LOCATION_INFO_0_RTT_FAC_LEGACY
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from L-LTF on the first selected
			Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from L-LTF on pri80 on the
			selected pri80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover pri80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_0_RTT_FAC_LEGACY_OFFSET                     0x00000000
#define RX_LOCATION_INFO_0_RTT_FAC_LEGACY_LSB                        0
#define RX_LOCATION_INFO_0_RTT_FAC_LEGACY_MASK                       0x0000ffff

/* Description		RX_LOCATION_INFO_0_RTT_FAC_LEGACY_EXT80
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from L-LTF on the second selected
			Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from L-LTF on ext80 on the
			selected ext80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover ext80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_0_RTT_FAC_LEGACY_EXT80_OFFSET               0x00000000
#define RX_LOCATION_INFO_0_RTT_FAC_LEGACY_EXT80_LSB                  16
#define RX_LOCATION_INFO_0_RTT_FAC_LEGACY_EXT80_MASK                 0xffff0000

/* Description		RX_LOCATION_INFO_1_RTT_FAC_VHT
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on the first
			selected Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on pri80 on the
			selected pri80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover pri80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_1_RTT_FAC_VHT_OFFSET                        0x00000004
#define RX_LOCATION_INFO_1_RTT_FAC_VHT_LSB                           0
#define RX_LOCATION_INFO_1_RTT_FAC_VHT_MASK                          0x0000ffff

/* Description		RX_LOCATION_INFO_1_RTT_FAC_VHT_EXT80
			
			For 20/40/80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on the second
			selected Rx chain
			
			
			
			For 80+80, this field shows the RTT first arrival
			correction value computed from (V)HT/HE-LTF on ext80 on the
			selected ext80 Rx chain
			
			
			
			16 bits, signed 12.4. 12 bits integer to cover -6.4us to
			6.4us, and 4 bits fraction to cover ext80 and 32x FAC
			interpolation
			
			
			
			clock unit is 320MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_1_RTT_FAC_VHT_EXT80_OFFSET                  0x00000004
#define RX_LOCATION_INFO_1_RTT_FAC_VHT_EXT80_LSB                     16
#define RX_LOCATION_INFO_1_RTT_FAC_VHT_EXT80_MASK                    0xffff0000

/* Description		RX_LOCATION_INFO_2_RTT_FAC_LEGACY_STATUS
			
			Status of rtt_fac_legacy
			
			
			
			<enum 0 location_fac_legacy_status_not_valid>
			
			<enum 1 location_fac_legacy_status_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_FAC_LEGACY_STATUS_OFFSET              0x00000008
#define RX_LOCATION_INFO_2_RTT_FAC_LEGACY_STATUS_LSB                 0
#define RX_LOCATION_INFO_2_RTT_FAC_LEGACY_STATUS_MASK                0x00000001

/* Description		RX_LOCATION_INFO_2_RTT_FAC_LEGACY_EXT80_STATUS
			
			Status of rtt_fac_legacy_ext80
			
			
			
			<enum 0 location_fac_legacy_ext80_status_not_valid>
			
			<enum 1 location_fac_legacy_ext80_status_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_FAC_LEGACY_EXT80_STATUS_OFFSET        0x00000008
#define RX_LOCATION_INFO_2_RTT_FAC_LEGACY_EXT80_STATUS_LSB           1
#define RX_LOCATION_INFO_2_RTT_FAC_LEGACY_EXT80_STATUS_MASK          0x00000002

/* Description		RX_LOCATION_INFO_2_RTT_FAC_VHT_STATUS
			
			Status of rtt_fac_vht
			
			
			
			<enum 0 location_fac_vht_status_not_valid>
			
			<enum 1 location_fac_vht_status_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_FAC_VHT_STATUS_OFFSET                 0x00000008
#define RX_LOCATION_INFO_2_RTT_FAC_VHT_STATUS_LSB                    2
#define RX_LOCATION_INFO_2_RTT_FAC_VHT_STATUS_MASK                   0x00000004

/* Description		RX_LOCATION_INFO_2_RTT_FAC_VHT_EXT80_STATUS
			
			Status of rtt_fac_vht_ext80
			
			
			
			<enum 0 location_fac_vht_ext80_status_not_valid>
			
			<enum 1 location_fac_vht_ext80_status_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_FAC_VHT_EXT80_STATUS_OFFSET           0x00000008
#define RX_LOCATION_INFO_2_RTT_FAC_VHT_EXT80_STATUS_LSB              3
#define RX_LOCATION_INFO_2_RTT_FAC_VHT_EXT80_STATUS_MASK             0x00000008

/* Description		RX_LOCATION_INFO_2_RTT_FAC_SIFS
			
			To support fine SIFS adjustment, need to provide FAC
			value @ integer number of 320 MHz clock cycles to MAC.?? It
			is from L-LTF if it is a Legacy packet and from (V)HT/HE-LTF
			if it is a (V)HT/HE packet
			
			
			
			12 bits, signed, no fractional part
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_FAC_SIFS_OFFSET                       0x00000008
#define RX_LOCATION_INFO_2_RTT_FAC_SIFS_LSB                          4
#define RX_LOCATION_INFO_2_RTT_FAC_SIFS_MASK                         0x0000fff0

/* Description		RX_LOCATION_INFO_2_RTT_FAC_SIFS_STATUS
			
			Status of rtt_fac_sifs
			
			0: not valid
			
			1: valid and from L-LTF
			
			2: valid and from (V)HT/HE-LTF
			
			3: reserved
			
			<legal 0-2>
*/
#define RX_LOCATION_INFO_2_RTT_FAC_SIFS_STATUS_OFFSET                0x00000008
#define RX_LOCATION_INFO_2_RTT_FAC_SIFS_STATUS_LSB                   16
#define RX_LOCATION_INFO_2_RTT_FAC_SIFS_STATUS_MASK                  0x00030000

/* Description		RX_LOCATION_INFO_2_RTT_CFR_STATUS
			
			Status of channel frequency response dump
			
			
			
			<enum 0 location_CFR_dump_not_valid>
			
			<enum 1 location_CFR_dump_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_CFR_STATUS_OFFSET                     0x00000008
#define RX_LOCATION_INFO_2_RTT_CFR_STATUS_LSB                        18
#define RX_LOCATION_INFO_2_RTT_CFR_STATUS_MASK                       0x00040000

/* Description		RX_LOCATION_INFO_2_RTT_CIR_STATUS
			
			Status of channel impulse response dump
			
			
			
			<enum 0 location_CIR_dump_not_valid>
			
			<enum 1 location_CIR_dump_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_CIR_STATUS_OFFSET                     0x00000008
#define RX_LOCATION_INFO_2_RTT_CIR_STATUS_LSB                        19
#define RX_LOCATION_INFO_2_RTT_CIR_STATUS_MASK                       0x00080000

/* Description		RX_LOCATION_INFO_2_RTT_CHANNEL_DUMP_SIZE
			
			Channel dump size.?? It shows how many tones in CFR in
			one chain, for example, it will show 52 for Legacy20 and 484
			for VHT160
			
			
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_CHANNEL_DUMP_SIZE_OFFSET              0x00000008
#define RX_LOCATION_INFO_2_RTT_CHANNEL_DUMP_SIZE_LSB                 20
#define RX_LOCATION_INFO_2_RTT_CHANNEL_DUMP_SIZE_MASK                0x7ff00000

/* Description		RX_LOCATION_INFO_2_RTT_HW_IFFT_MODE
			
			Indicator showing if HW IFFT mode or SW IFFT mode
			
			
			
			<enum 0 location_sw_ifft_mode>
			
			<enum 1 location_hw_ifft_mode>
			
			<legal all>
*/
#define RX_LOCATION_INFO_2_RTT_HW_IFFT_MODE_OFFSET                   0x00000008
#define RX_LOCATION_INFO_2_RTT_HW_IFFT_MODE_LSB                      31
#define RX_LOCATION_INFO_2_RTT_HW_IFFT_MODE_MASK                     0x80000000

/* Description		RX_LOCATION_INFO_3_RTT_BTCF_STATUS
			
			Indicate if BTCF is used to capture the timestamps
			
			
			
			<enum 0 location_not_BTCF_based_ts>
			
			<enum 1 location_BTCF_based_ts>
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_BTCF_STATUS_OFFSET                    0x0000000c
#define RX_LOCATION_INFO_3_RTT_BTCF_STATUS_LSB                       0
#define RX_LOCATION_INFO_3_RTT_BTCF_STATUS_MASK                      0x00000001

/* Description		RX_LOCATION_INFO_3_RTT_PREAMBLE_TYPE
			
			Indicate preamble type
			
			
			
			<enum 0 location_preamble_type_legacy>
			
			<enum 1 location_preamble_type_ht>
			
			<enum 2 location_preamble_type_vht>
			
			<enum 3 location_preamble_type_he_su_4xltf>
			
			<enum 4 location_preamble_type_he_su_2xltf>
			
			<enum 5 location_preamble_type_he_su_1xltf>
			
			<enum 6
			location_preamble_type_he_trigger_based_ul_4xltf>
			
			<enum 7
			location_preamble_type_he_trigger_based_ul_2xltf>
			
			<enum 8
			location_preamble_type_he_trigger_based_ul_1xltf>
			
			<enum 9 location_preamble_type_he_mu_4xltf>
			
			<enum 10 location_preamble_type_he_mu_2xltf>
			
			<enum 11 location_preamble_type_he_mu_1xltf>
			
			<enum 12
			location_preamble_type_he_extended_range_su_4xltf>
			
			<enum 13
			location_preamble_type_he_extended_range_su_2xltf>
			
			<enum 14
			location_preamble_type_he_extended_range_su_1xltf>
			
			<legal 0-14>
*/
#define RX_LOCATION_INFO_3_RTT_PREAMBLE_TYPE_OFFSET                  0x0000000c
#define RX_LOCATION_INFO_3_RTT_PREAMBLE_TYPE_LSB                     1
#define RX_LOCATION_INFO_3_RTT_PREAMBLE_TYPE_MASK                    0x0000003e

/* Description		RX_LOCATION_INFO_3_RTT_PKT_BW_LEG
			
			Indicate the bandwidth of L-LTF
			
			
			
			<enum 0 location_pkt_bw_20MHz>
			
			<enum 1 location_pkt_bw_40MHz>
			
			<enum 2 location_pkt_bw_80MHz>
			
			<enum 3 location_pkt_bw_160MHz>
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_PKT_BW_LEG_OFFSET                     0x0000000c
#define RX_LOCATION_INFO_3_RTT_PKT_BW_LEG_LSB                        6
#define RX_LOCATION_INFO_3_RTT_PKT_BW_LEG_MASK                       0x000000c0

/* Description		RX_LOCATION_INFO_3_RTT_PKT_BW_VHT
			
			Indicate the bandwidth of (V)HT/HE-LTF
			
			
			
			<enum 0 location_pkt_bw_20MHz>
			
			<enum 1 location_pkt_bw_40MHz>
			
			<enum 2 location_pkt_bw_80MHz>
			
			<enum 3 location_pkt_bw_160MHz>
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_PKT_BW_VHT_OFFSET                     0x0000000c
#define RX_LOCATION_INFO_3_RTT_PKT_BW_VHT_LSB                        8
#define RX_LOCATION_INFO_3_RTT_PKT_BW_VHT_MASK                       0x00000300

/* Description		RX_LOCATION_INFO_3_RTT_GI_TYPE
			
			Indicate GI (guard interval) type
			
			
			
			<enum 0     gi_0_8_us > HE related GI. Can also be used
			for HE
			
			<enum 1     gi_0_4_us > HE related GI. Can also be used
			for HE
			
			<enum 2     gi_1_6_us > HE related GI
			
			<enum 3     gi_3_2_us > HE related GI
			
			<legal 0 - 3>
*/
#define RX_LOCATION_INFO_3_RTT_GI_TYPE_OFFSET                        0x0000000c
#define RX_LOCATION_INFO_3_RTT_GI_TYPE_LSB                           10
#define RX_LOCATION_INFO_3_RTT_GI_TYPE_MASK                          0x00000c00

/* Description		RX_LOCATION_INFO_3_RTT_MCS_RATE
			
			Bits 0~4 indicate MCS rate, if Legacy, 
			
			0: 48 Mbps,
			
			1: 24 Mbps,
			
			2: 12 Mbps,
			
			3: 6 Mbps,
			
			4: 54 Mbps,
			
			5: 36 Mbps,
			
			6: 18 Mbps,
			
			7: 9 Mbps,
			
			
			
			if HT, 0-7: MCS0-MCS7, 
			
			if VHT, 0-9: MCS0-MCS9, 
			
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_MCS_RATE_OFFSET                       0x0000000c
#define RX_LOCATION_INFO_3_RTT_MCS_RATE_LSB                          12
#define RX_LOCATION_INFO_3_RTT_MCS_RATE_MASK                         0x0001f000

/* Description		RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN
			
			For 20/40/80, this field shows the first selected Rx
			chain that is used in HW IFFT mode
			
			
			
			For 80+80, this field shows the selected pri80 Rx chain
			that is used in HW IFFT mode
			
			
			
			<enum 0 location_strongest_chain_is_0>
			
			<enum 1 location_strongest_chain_is_1>
			
			<enum 2 location_strongest_chain_is_2>
			
			<enum 3 location_strongest_chain_is_3>
			
			<enum 4 location_strongest_chain_is_4>
			
			<enum 5 location_strongest_chain_is_5>
			
			<enum 6 location_strongest_chain_is_6>
			
			<enum 7 location_strongest_chain_is_7>
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_OFFSET                0x0000000c
#define RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_LSB                   17
#define RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_MASK                  0x000e0000

/* Description		RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_EXT80
			
			For 20/40/80, this field shows the second selected Rx
			chain that is used in HW IFFT mode
			
			
			
			For 80+80, this field shows the selected ext80 Rx chain
			that is used in HW IFFT mode
			
			
			
			<enum 0 location_strongest_chain_is_0>
			
			<enum 1 location_strongest_chain_is_1>
			
			<enum 2 location_strongest_chain_is_2>
			
			<enum 3 location_strongest_chain_is_3>
			
			<enum 4 location_strongest_chain_is_4>
			
			<enum 5 location_strongest_chain_is_5>
			
			<enum 6 location_strongest_chain_is_6>
			
			<enum 7 location_strongest_chain_is_7>
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_EXT80_OFFSET          0x0000000c
#define RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_EXT80_LSB             20
#define RX_LOCATION_INFO_3_RTT_STRONGEST_CHAIN_EXT80_MASK            0x00700000

/* Description		RX_LOCATION_INFO_3_RTT_RX_CHAIN_MASK
			
			Rx chain mask, each bit is a Rx chain
			
			0: the Rx chain is not used
			
			1: the Rx chain is used
			
			Support up to 8 Rx chains
			
			<legal all>
*/
#define RX_LOCATION_INFO_3_RTT_RX_CHAIN_MASK_OFFSET                  0x0000000c
#define RX_LOCATION_INFO_3_RTT_RX_CHAIN_MASK_LSB                     23
#define RX_LOCATION_INFO_3_RTT_RX_CHAIN_MASK_MASK                    0x7f800000

/* Description		RX_LOCATION_INFO_3_RESERVED_3
			
			<legal 0>
*/
#define RX_LOCATION_INFO_3_RESERVED_3_OFFSET                         0x0000000c
#define RX_LOCATION_INFO_3_RESERVED_3_LSB                            31
#define RX_LOCATION_INFO_3_RESERVED_3_MASK                           0x80000000

/* Description		RX_LOCATION_INFO_4_RX_START_TS
			
			RX packet start timestamp
			
			
			
			It reports the time the first L-STF ADC sample arrived
			at RX antenna
			
			
			
			clock unit is 480MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_4_RX_START_TS_OFFSET                        0x00000010
#define RX_LOCATION_INFO_4_RX_START_TS_LSB                           0
#define RX_LOCATION_INFO_4_RX_START_TS_MASK                          0xffffffff

/* Description		RX_LOCATION_INFO_5_RX_END_TS
			
			RX packet end timestamp
			
			
			
			It reports the time the last symbol's last ADC sample
			arrived at RX antenna
			
			
			
			clock unit is 480MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_5_RX_END_TS_OFFSET                          0x00000014
#define RX_LOCATION_INFO_5_RX_END_TS_LSB                             0
#define RX_LOCATION_INFO_5_RX_END_TS_MASK                            0xffffffff

/* Description		RX_LOCATION_INFO_6_SFO_PHASE_PKT_START
			
			The phase of the SFO of the first symbol's first FFT
			input sample
			
			
			
			12 bits, signed 6.6. 6 bits integer to cover -66.7ns to
			66.7ns, and 6 bits fraction to provide a resolution of
			0.03ns
			
			
			
			clock unit is 480MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_6_SFO_PHASE_PKT_START_OFFSET                0x00000018
#define RX_LOCATION_INFO_6_SFO_PHASE_PKT_START_LSB                   0
#define RX_LOCATION_INFO_6_SFO_PHASE_PKT_START_MASK                  0x00000fff

/* Description		RX_LOCATION_INFO_6_SFO_PHASE_PKT_END
			
			The phase of the SFO of the last symbol's last FFT input
			sample
			
			
			
			12 bits, signed 6.6. 6 bits integer to cover -66.7ns to
			66.7ns, and 6 bits fraction to provide a resolution of
			0.03ns
			
			
			
			clock unit is 480MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_6_SFO_PHASE_PKT_END_OFFSET                  0x00000018
#define RX_LOCATION_INFO_6_SFO_PHASE_PKT_END_LSB                     12
#define RX_LOCATION_INFO_6_SFO_PHASE_PKT_END_MASK                    0x00fff000

/* Description		RX_LOCATION_INFO_6_RTT_CHE_BUFFER_POINTER_HIGH8
			
			The high 8 bits of the 40 bits pointer pointed to the
			external RTT channel information buffer
			
			
			
			8 bits
			
			<legal all>
*/
#define RX_LOCATION_INFO_6_RTT_CHE_BUFFER_POINTER_HIGH8_OFFSET       0x00000018
#define RX_LOCATION_INFO_6_RTT_CHE_BUFFER_POINTER_HIGH8_LSB          24
#define RX_LOCATION_INFO_6_RTT_CHE_BUFFER_POINTER_HIGH8_MASK         0xff000000

/* Description		RX_LOCATION_INFO_7_RTT_CHE_BUFFER_POINTER_LOW32
			
			The low 32 bits of the 40 bits pointer pointed to the
			external RTT channel information buffer
			
			
			
			32 bits
			
			<legal all>
*/
#define RX_LOCATION_INFO_7_RTT_CHE_BUFFER_POINTER_LOW32_OFFSET       0x0000001c
#define RX_LOCATION_INFO_7_RTT_CHE_BUFFER_POINTER_LOW32_LSB          0
#define RX_LOCATION_INFO_7_RTT_CHE_BUFFER_POINTER_LOW32_MASK         0xffffffff

/* Description		RX_LOCATION_INFO_8_RTT_CFO_MEASUREMENT
			
			CFO measurement. Needed for passive locationing
			
			
			
			14 bits, signed 1.13. 13 bits fraction to provide a
			resolution of 153 Hz
			
			
			
			In units of cycles/800 ns
			
			<legal all>
*/
#define RX_LOCATION_INFO_8_RTT_CFO_MEASUREMENT_OFFSET                0x00000020
#define RX_LOCATION_INFO_8_RTT_CFO_MEASUREMENT_LSB                   0
#define RX_LOCATION_INFO_8_RTT_CFO_MEASUREMENT_MASK                  0x00003fff

/* Description		RX_LOCATION_INFO_8_RTT_CHAN_SPREAD
			
			Channel delay spread measurement. Needed for selecting
			GI length
			
			
			
			8 bits, unsigned. At 25 ns step. Can represent up to
			6375 ns
			
			
			
			In units of cycles @ 40 MHz
			
			<legal all>
*/
#define RX_LOCATION_INFO_8_RTT_CHAN_SPREAD_OFFSET                    0x00000020
#define RX_LOCATION_INFO_8_RTT_CHAN_SPREAD_LSB                       14
#define RX_LOCATION_INFO_8_RTT_CHAN_SPREAD_MASK                      0x003fc000

/* Description		RX_LOCATION_INFO_8_RTT_TIMING_BACKOFF_SEL
			
			Indicate which timing backoff value is used
			
			
			
			<enum 0 timing_backoff_low_rssi>
			
			<enum 1 timing_backoff_mid_rssi>
			
			<enum 2 timing_backoff_high_rssi>
			
			<enum 3 reserved>
			
			<legal all>
*/
#define RX_LOCATION_INFO_8_RTT_TIMING_BACKOFF_SEL_OFFSET             0x00000020
#define RX_LOCATION_INFO_8_RTT_TIMING_BACKOFF_SEL_LSB                22
#define RX_LOCATION_INFO_8_RTT_TIMING_BACKOFF_SEL_MASK               0x00c00000

/* Description		RX_LOCATION_INFO_8_RESERVED_8
			
			<legal 0>
*/
#define RX_LOCATION_INFO_8_RESERVED_8_OFFSET                         0x00000020
#define RX_LOCATION_INFO_8_RESERVED_8_LSB                            24
#define RX_LOCATION_INFO_8_RESERVED_8_MASK                           0x7f000000

/* Description		RX_LOCATION_INFO_8_RX_LOCATION_INFO_VALID
			
			<enum 0 rx_location_info_is_not_valid>
			
			<enum 1 rx_location_info_is_valid>
			
			<legal all>
*/
#define RX_LOCATION_INFO_8_RX_LOCATION_INFO_VALID_OFFSET             0x00000020
#define RX_LOCATION_INFO_8_RX_LOCATION_INFO_VALID_LSB                31
#define RX_LOCATION_INFO_8_RX_LOCATION_INFO_VALID_MASK               0x80000000


#endif // _RX_LOCATION_INFO_H_
