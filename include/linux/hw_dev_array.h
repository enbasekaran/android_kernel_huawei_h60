#ifndef _HUAWEI_DEV_ARRAY_H_
#define _HUAWEI_DEV_ARRAY_H_
#include "hw_dev_dec.h"

typedef struct {
    int devices_id;
    char* devices_name;
}hw_dec_struct;

static hw_dec_struct hw_dec_device_array[] =
{
    { DEV_I2C_TOUCH_PANEL,"touch_panel" },// id : 0    order number 1
    { DEV_I2C_COMPASS,"compass" },// id : 1    order number 2
    { DEV_I2C_G_SENSOR,"g_sensor" },// id : 2    order number 3
    { DEV_I2C_CAMERA_MAIN,"camera_main" },// id : 3    order number 4
    { DEV_I2C_CAMERA_SLAVE,"camera_slave" },// id : 4    order number 5
    { DEV_I2C_KEYPAD,"keypad" },// id : 5    order number 6
    { DEV_I2C_APS,"aps" },// id : 6    order number 7
    { DEV_I2C_GYROSCOPE,"gyroscope" },//  id : 7    order number 8
    { DEV_I2C_NFC,"nfc" },// id : 8    order number 9
    { DEV_I2C_DC_DC,"dc_dc" },// id : 9    order number 10
    { DEV_I2C_SPEAKER,"speaker" },// id : 10    order number 11
    { DEV_I2C_OFN,"ofn" },// id : 11    order number 12
    { DEV_I2C_TPS,"tps" },// id : 12    order number 13
    { DEV_I2C_L_SENSOR,"l_sensor" },// id : 13    order number 14
    { DEV_I2C_CHARGER,"charge" },// id : 14    order number 15
    { DEV_I2C_BATTERY,"battery" },// id : 15    order number 16
    { DEV_I2C_NCT,"nct" },// id : 16    order number 17
    { DEV_I2C_MHL,"mhl" },// id : 17    order number 18
    { DEV_I2C_AUDIENCE,"audience" },// id : 18    order number 19
    { DEV_I2C_IRDA,"irda" },// id : 19    order number 20
    { DEV_I2C_CS,"hand_sensor"},// id : 20    order number 21
    { DEV_I2C_USB_SWITCH,"usb_switch"},//  id : 21    order number 22
    { DEV_I2C_PMU_DCDC, "pmu_dcdc"},//  id : 22    order number 23
    { DEV_I2C_CAMERA_PMU, "camera_pmu"},//  id : 23    order number 24
    { DEV_I2C_CPU_CHIP, "cpu_chip"},//  id : 24    order number 25
    { DEV_I2C_MAX,"NULL" },// id : 25    order number 26
    { DEV_CONNECTIVITY_WIFI,"wifi" },// id : 26    order number 27
    { DEV_CONNECTIVITY_BT,"bt" },// id : 27   order number 28
    { DEV_CONNECTIVITY_FM,"fm" },// id : 28    order number 29
    { DEV_CONNECTIVITY_GPS,"gps" },// id : 29   order number 30
    { DEV_CONNECTIVITY_GPU,"gpu" },// id : 30   order number 31
};

#endif
