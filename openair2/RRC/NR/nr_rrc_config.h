/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file nr_rrc_config.c
 * \brief rrc config for gNB
 * \author Raymond Knopp, WEI-TAI CHEN
 * \date 2018
 * \version 1.0
 * \company Eurecom, NTUST
 * \email: raymond.knopp@eurecom.fr, kroempa@gmail.com
 */

#ifndef __NR_RRC_CONFIG_H__
#define __NR_RRC_CONFIG_H__

#include "nr_rrc_defs.h"

typedef struct rlc_bearer_config_s{
  long        LogicalChannelIdentity[MAX_NUM_CCs];
  long        servedRadioBearer_present[MAX_NUM_CCs];
  long        srb_Identity[MAX_NUM_CCs];
  long        drb_Identity[MAX_NUM_CCs];
  long        reestablishRLC[MAX_NUM_CCs];
  long        rlc_Config_present[MAX_NUM_CCs];
  long        ul_AM_sn_FieldLength[MAX_NUM_CCs];
  long        t_PollRetransmit[MAX_NUM_CCs];
  long        pollPDU[MAX_NUM_CCs];
  long        pollByte[MAX_NUM_CCs];
  long        maxRetxThreshold[MAX_NUM_CCs];
  long        dl_AM_sn_FieldLength[MAX_NUM_CCs];
  long        dl_AM_t_Reassembly[MAX_NUM_CCs];
  long        t_StatusProhibit[MAX_NUM_CCs];
  long        ul_UM_sn_FieldLength[MAX_NUM_CCs];
  long        dl_UM_sn_FieldLength[MAX_NUM_CCs];
  long        dl_UM_t_Reassembly[MAX_NUM_CCs];
  long        priority[MAX_NUM_CCs];
  long        prioritisedBitRate[MAX_NUM_CCs];
  long        bucketSizeDuration[MAX_NUM_CCs];
  long        allowedServingCells[MAX_NUM_CCs];
  long        subcarrierspacing[MAX_NUM_CCs];
  long        maxPUSCH_Duration[MAX_NUM_CCs];
  long        configuredGrantType1Allowed[MAX_NUM_CCs];
  long        logicalChannelGroup[MAX_NUM_CCs];
  long        schedulingRequestID[MAX_NUM_CCs]; /* OPTIONAL */
  int         logicalChannelSR_Mask[MAX_NUM_CCs];
  int         logicalChannelSR_DelayTimerApplied[MAX_NUM_CCs];
}rlc_bearer_config_t;

typedef struct mac_cellgroup_s{
  long        DRX_Config_PR[MAX_NUM_CCs];
  long        drx_onDurationTimer_PR[MAX_NUM_CCs];
  long        subMilliSeconds[MAX_NUM_CCs];
  long        milliSeconds[MAX_NUM_CCs];
  long        drx_InactivityTimer[MAX_NUM_CCs];
  long        drx_HARQ_RTT_TimerDL[MAX_NUM_CCs];
  long        drx_HARQ_RTT_TimerUL[MAX_NUM_CCs];
  long        drx_RetransmissionTimerDL[MAX_NUM_CCs];
  long        drx_RetransmissionTimerUL[MAX_NUM_CCs];
  long        drx_LongCycleStartOffset_PR[MAX_NUM_CCs];
  long        drx_LongCycleStartOffset[MAX_NUM_CCs];
  long        drx_ShortCycle[MAX_NUM_CCs];
  long        drx_ShortCycleTimer[MAX_NUM_CCs];
  long        drx_SlotOffset[MAX_NUM_CCs];
  long        schedulingRequestId[MAX_NUM_CCs];
  long        sr_ProhibitTimer[MAX_NUM_CCs];
  long        sr_TransMax[MAX_NUM_CCs];
  long        periodicBSR_Timer[MAX_NUM_CCs];
  long        retxBSR_Timer[MAX_NUM_CCs];
  long        logicalChannelSR_DelayTimer[MAX_NUM_CCs];
  long        tag_Id[MAX_NUM_CCs];
  long        timeAlignmentTimer[MAX_NUM_CCs];
  long        PHR_Config_PR[MAX_NUM_CCs];
  long        phr_PeriodicTimer[MAX_NUM_CCs];
  long        phr_ProhibitTimer[MAX_NUM_CCs];
  long        phr_Tx_PowerFactorChange[MAX_NUM_CCs];
  int         multiplePHR[MAX_NUM_CCs];
  int         phr_Type2SpCell[MAX_NUM_CCs];
  int         phr_Type2OtherCell[MAX_NUM_CCs];
  long        phr_ModeOtherCG[MAX_NUM_CCs];
  int         skipUplinkTxDynamic[MAX_NUM_CCs];
}mac_cellgroup_t;

typedef struct physicalcellgroup_s{
  long        harq_ACK_SpatialBundlingPUCCH[MAX_NUM_CCs];
  long        harq_ACK_SpatialBundlingPUSCH[MAX_NUM_CCs];
  long        p_NR[MAX_NUM_CCs];
  long        pdsch_HARQ_ACK_Codebook[MAX_NUM_CCs];
  long        tpc_SRS_RNTI[MAX_NUM_CCs];
  long        tpc_PUCCH_RNTI[MAX_NUM_CCs];
  long        tpc_PUSCH_RNTI[MAX_NUM_CCs];
  long        sp_CSI_RNTI[MAX_NUM_CCs];
  long        RNTI_Value_PR[MAX_NUM_CCs];
  long        RNTI_Value[MAX_NUM_CCs];
}physicalcellgroup_t;

uint64_t get_ssb_bitmap(NR_ServingCellConfigCommon_t *scc);
void rrc_coreset_config(NR_ControlResourceSet_t *coreset,
                        int bwp_id,
                        int curr_bwp,
                        uint64_t ssb_bitmap);
void nr_rrc_config_dl_tda(NR_ServingCellConfigCommon_t *scc,
                          NR_PDSCH_TimeDomainResourceAllocationList_t	*pdsch_TimeDomainAllocationList,
                          int curr_bwp);
void nr_rrc_config_ul_tda(NR_ServingCellConfigCommon_t *scc, int min_fb_delay);
void config_pucch_resset0(NR_PUCCH_Config_t *pucch_Config, int uid, int curr_bwp, NR_UE_NR_Capability_t *uecap);
void config_pucch_resset1(NR_PUCCH_Config_t *pucch_Config, NR_UE_NR_Capability_t *uecap);
void set_dl_DataToUL_ACK(NR_PUCCH_Config_t *pucch_Config, int min_feedback_time);
void set_pucch_power_config(NR_PUCCH_Config_t *pucch_Config, int do_csirs);
void scheduling_request_config(NR_ServingCellConfigCommon_t *scc,
                               NR_PUCCH_Config_t *pucch_Config);
void config_csirs(NR_ServingCellConfigCommon_t *servingcellconfigcommon,
                  NR_CSI_MeasConfig_t *csi_MeasConfig,
                  int uid,
                  int num_dl_antenna_ports,
                  int curr_bwp,
                  int do_csirs);
void config_csiim(int do_csirs, int dl_antenna_ports, int curr_bwp,
                  NR_CSI_MeasConfig_t *csi_MeasConfig);
void config_srs(NR_SetupRelease_SRS_Config_t *setup_release_srs_Config,
                const NR_ServingCellConfigCommon_t *servingcellconfigcommon,
                const int uid,
                const int do_srs);
void set_dl_mcs_table(int scs,
                      NR_UE_NR_Capability_t *cap,
                      NR_SpCellConfig_t *SpCellConfig,
                      NR_BWP_DownlinkDedicated_t *bwp_Dedicated,
                      NR_ServingCellConfigCommon_t *scc);
void prepare_sim_uecap(NR_UE_NR_Capability_t *cap,
                       NR_ServingCellConfigCommon_t *scc,
                       int numerology,
                       int rbsize,
                       int mcs_table);

#endif
