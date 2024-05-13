#include "my_gui.h"
#include "lvgl/lvgl.h"
#include "lv_drivers/win32drv/win32drv.h"

void lv_100ask_demo_course_3_3_1(void)
{
    // ����һ���飬�Ժ���Ҫʹ�ü��̻��������ť���ƵĲ���(����)��ӽ�ȥ�����ҽ������豸�������
    // ��������������ΪĬ���飬��ô������Щ�ڴ���ʱ����ӵ�Ĭ����Ĳ���(����)�Ϳ���ʡ�� lv_group_add_obj()
    lv_group_t * g = lv_group_create();

    // �����洴����������ΪĬ����
    // ����Ժ󴴽��Ĳ���(����)��ʹ��Ĭ�����Ǳ���Ҫ���䴴��֮ǰ���ú�Ĭ���飬������Ч
    lv_group_set_default(g);

    // �������豸�������(ʹ��ǰ�ȴ�����ע�͵���ͷ�ļ�)
    lv_indev_set_group(lv_win32_keypad_device_object, g);     // ����
    // lv_indev_set_group(lv_win32_encoder_device_object, g);      // ����ϵĹ���(������)


    /* ����һ��btn����(����) */
    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());       // ����һ��btn����(����),���ĸ������ǻ��Ļ����
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -100);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());       // ����һ��btn����(����),���ĸ������ǻ��Ļ����
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * btn3 = lv_btn_create(lv_scr_act());       // ����һ��btn����(����),���ĸ������ǻ��Ļ����
    lv_obj_set_size(btn3, 100, 50);
    lv_obj_align_to(btn3, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * btn4 = lv_btn_create(lv_scr_act());       // ����һ��btn����(����),���ĸ������ǻ��Ļ����
    lv_obj_set_size(btn4, 100, 50);
    lv_obj_align_to(btn4, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    // lv_obj_t * slider = lv_slider_create(lv_scr_act());
    // lv_obj_align_to(slider, btn4, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    // ������(����)��ӵ��飬���������Ĭ���飬�������ʡ��
    lv_group_add_obj(g, btn1);
    lv_group_add_obj(g, btn2);
    lv_group_add_obj(g, btn3);
    lv_group_add_obj(g, btn4);
    // lv_group_add_obj(g, slider);

    lv_group_focus_obj(btn1);
}

