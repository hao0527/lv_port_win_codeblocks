#include "my_test.h"
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

static lv_group_t *group1;

static void textarea_event_handler(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target(e);
    LV_LOG_USER("Enter was pressed. The current text is: %s", lv_textarea_get_text(ta));
}

void lv_example_textarea_my(void)
{
    lv_obj_t * ta = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(ta, true);
    lv_textarea_set_accepted_chars(ta, "0123456789");   // ���ý����������ַ�
    lv_obj_align(ta, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_width(ta, 200);
    lv_obj_add_event_cb(ta, textarea_event_handler, LV_EVENT_READY, NULL);
    lv_obj_add_state(ta, LV_STATE_FOCUSED); /*To be sure the cursor is visible*/

    lv_obj_t * ta2 = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(ta2, true);
    lv_textarea_set_accepted_chars(ta2, "0123456789");   // ���ý����������ַ�
    lv_obj_align(ta2, LV_ALIGN_TOP_MID, 0, 60);
    lv_obj_set_width(ta2, 200);
    lv_obj_add_event_cb(ta2, textarea_event_handler, LV_EVENT_READY, NULL);
    lv_obj_clear_state(ta2, LV_STATE_FOCUSED); /*To be sure the cursor is visible*/

    // ����group
    group1 = lv_group_create();
    lv_group_add_obj(group1, ta);
    lv_group_add_obj(group1, ta2);
    lv_indev_set_group(lv_win32_keypad_device_object, group1);     // �����̺���1����
}
