#include "my_gui.h"
#include "lvgl/lvgl.h"
#include "lv_drivers/win32drv/win32drv.h"

#define  BATTERY_OUTLINE_W    40 //���ͼ����
#define  BATTERY_OUTLINE_H    20 //���ͼ��߶�

static void my_gui_battery_cb(void* p, int32_t v)
{
    //ʵ�ֱ�ɫЧ������ص�������20% ��ɫ
    static int32_t cnt;
    if (cnt >= BATTERY_OUTLINE_W * 0.2 && v < BATTERY_OUTLINE_W * 0.2)
    {
        lv_obj_set_style_bg_color(p, lv_color_hex(0xff0000), 0);
    }
    else if (v >= BATTERY_OUTLINE_W * 0.2 && cnt < BATTERY_OUTLINE_W * 0.2)
    {
        lv_obj_set_style_bg_color(p, lv_color_hex(0xff00), 0);
    }
    cnt = v;

    //�޸ĵ�����ɫobj���
    lv_obj_set_width(p, v);

    //�޸ĵ�ذٷֱ�
    lv_obj_t *text = lv_obj_get_child(lv_obj_get_parent(p), -1);
    lv_label_set_text_fmt(text, "%d", v*100/(BATTERY_OUTLINE_W-4));
}

static void my_gui_battery_init(void)
{
    lv_obj_t* outline = lv_obj_create(lv_scr_act());

    //����border��pading
    lv_obj_set_style_border_width(outline, 2, 0);
    lv_obj_set_style_pad_all(outline, 0, 0);

    //����Բ��
    lv_obj_set_style_radius(outline, 8, 0);

    //�رչ�����
    lv_obj_clear_flag(outline, LV_OBJ_FLAG_SCROLLABLE);

    //���ÿ��
    lv_obj_set_size(outline, BATTERY_OUTLINE_W, BATTERY_OUTLINE_H);

    //���ж���
    lv_obj_align(outline, LV_ALIGN_CENTER, 0, 0);

    //��ص������obj
    lv_obj_t* pad = lv_obj_create(outline);


    //����outline
    lv_obj_set_style_outline_width(pad, 0, 0);
    lv_obj_set_style_outline_pad(pad, 0, 0);
    lv_obj_set_style_border_width(pad, 0, 0);
    //���ñ���ɫ
    lv_obj_set_style_bg_color(pad, lv_color_hex(0xff0000), 0);

    //���ÿ��
    lv_obj_set_size(pad, BATTERY_OUTLINE_W, BATTERY_OUTLINE_H-4);
    lv_obj_set_style_border_width(pad, 0, 0);

    //����Բ��
    lv_obj_set_style_radius(pad, 8, 0);

    //������ʾ
    lv_obj_align(outline, LV_ALIGN_TOP_RIGHT, 0, 0);

    //�رչ�����
    lv_obj_clear_flag(pad, LV_OBJ_FLAG_SCROLLABLE);

    //��ذٷֱ�
    lv_obj_t* label = lv_label_create(outline);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    //���ö����� ģ�µ�ص����仯
    lv_anim_t a;
    lv_anim_init(&a);

    /*Set the "animator" function*/
    lv_anim_set_exec_cb(&a, my_gui_battery_cb);

    /*Set the "animator" function*/
    lv_anim_set_var(&a, pad);

    /*Length of the animation [ms]*/
    lv_anim_set_time(&a, 10000);

    /*Set start and end values. E.g. 0, 150*/
    lv_anim_set_values(&a, 0, BATTERY_OUTLINE_W-4);

    /*Time to wait before starting the animation [ms]*/
    lv_anim_set_delay(&a, 1000);

    /*Play the animation backward too with this duration. Default is 0 (disabled) [ms]*/
    lv_anim_set_playback_time(&a, 0);

    /*Delay before playback. Default is 0 (disabled) [ms]*/
    lv_anim_set_playback_delay(&a, 0);

    /*Number of repetitions. Default is 1.  LV_ANIM_REPEAT_INFINIT for infinite repetition*/
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);

    /*Delay before repeat. Default is 0 (disabled) [ms]*/
    lv_anim_set_repeat_delay(&a, 1000);

    /* START THE ANIMATION
     *------------------*/
    lv_anim_start(&a);                             /*Start the animation*/
}

static void my_gui_tabview_init(void)
{
    /*Create a Tab view object*/
    lv_obj_t * tabview;
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 40);  // tab_size ����ѡ��߶�
    lv_obj_set_size(tabview, 240, 300);  // ���������С
    lv_obj_align(tabview, LV_ALIGN_TOP_MID, 0, 20);

#if 1
    // tabview������һ��tab
    lv_obj_t * tab1 = lv_tabview_add_tab(tabview, "Config");
    lv_obj_set_scrollbar_mode(tab1, LV_SCROLLBAR_MODE_OFF);     // �ع�����

    // ������ʽ��Ӧ����list��ֱ�Ǳߣ�͸���������ޱ߽�ֵ
    static lv_style_t style;    // ��ҪΪstatic����Ȼ��������
    lv_style_init(&style);
    lv_style_set_radius(&style, 0);
    lv_style_set_bg_opa(&style, LV_OPA_TRANSP); // ����͸������
    lv_style_set_border_width(&style, 0);

    /*Add content to the tab1*/
    lv_obj_t * list1;
    list1 = lv_list_create(tab1);
    lv_obj_set_size(list1, 240, 260);
    lv_obj_align(list1, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_add_style(list1, &style, 0);

    // ��������
    lv_obj_t * btn1;
    lv_obj_t * btn2;
    lv_obj_t * btn3;
    lv_obj_t * btn4;
    btn1 = lv_list_add_btn(list1, NULL, "Freq:");
    lv_obj_add_event_cb(btn1, NULL, LV_EVENT_ALL, NULL);

    btn2 = lv_list_add_btn(list1, NULL, "Rate:");
    lv_obj_add_event_cb(btn2, NULL, LV_EVENT_ALL, NULL);

    btn3 = lv_list_add_btn(list1, NULL, "Volume:");
    lv_obj_add_event_cb(btn3, NULL, LV_EVENT_ALL, NULL);

    btn4 = lv_list_add_btn(list1, NULL, "Brightness:");
    lv_obj_add_event_cb(btn4, NULL, LV_EVENT_ALL, NULL);

    // ����group
    lv_group_t * group1 = lv_group_create();
    lv_indev_set_group(lv_win32_keypad_device_object, group1);     // �����̺������
    lv_group_add_obj(group1, btn1);
    lv_group_add_obj(group1, btn2);
    lv_group_add_obj(group1, btn3);
    lv_group_add_obj(group1, btn4);
    lv_group_set_default(group1);   // ����ΪĬ����
#endif

#if 1
    // tabview������һ��tab
    lv_obj_t * tab2 = lv_tabview_add_tab(tabview, "Comm");
    lv_obj_set_scrollbar_mode(tab2, LV_SCROLLBAR_MODE_OFF);

    /*Add content to the tab2*/
    lv_obj_t * table = lv_table_create(tab2);
    lv_group_remove_obj(table); // ������group
    lv_table_set_cell_value(table, 0, 0, "ISSI");
    lv_table_set_cell_value(table, 0, 1, "0db");
    lv_table_set_cell_value(table, 1, 0, "TXCnt");
    lv_table_set_cell_value(table, 1, 1, "0");
    lv_table_set_cell_value(table, 2, 0, "RXCnt");
    lv_table_set_cell_value(table, 2, 1, "0");

    /*Set a smaller height to the table. It'll make it scrollable*/
    lv_table_set_col_width(table, 0, 105);
    lv_table_set_col_width(table, 1, 105);
    // lv_obj_set_height(table, 220);
    lv_obj_align(table, LV_ALIGN_TOP_MID, 0, 0);
#endif

#if 1
    // tabview������һ��tab
    lv_obj_t * tab3 = lv_tabview_add_tab(tabview, "About");
    lv_obj_set_scrollbar_mode(tab3, LV_SCROLLBAR_MODE_OFF);

    /*Add content to the tab3*/
    lv_obj_t * label = lv_label_create(tab3);
    lv_label_set_text(label, "Version: 0.0.2");
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 10, 10);
#endif
}

void my_gui_init(void)
{
    my_gui_tabview_init();
    my_gui_battery_init();
}
