# _*_ coding:utf-8 _*_

__author__ = 'srea'
__date__ = '2018/06/01 14:07'

import xadmin
from xadmin import views
from .models import EmailVerifyRecode,Banner


class BaseSetting(object):
    enable_themes = True
    use_bootswatch = True


class GlobalSettings(object):
    site_title = "学生自主学习后台管理系统"
    site_footer = "学生自主学习网"
    menu_style = 'accordion'


class EmailVerifyRecodeAdmin(object):
    list_display = ['code','email','send_type','send_time']
    search_fields =['code','email','send_type']
    list_filter = ['code','email','send_type','send_time']


class BannerAdmin(object):
    list_display = ['title', 'image', 'url', 'index','addtime']
    search_fields = ['title', 'image', 'url', 'index']
    list_filter = ['title', 'image', 'url', 'index','addtime']


xadmin.site.register(EmailVerifyRecode,EmailVerifyRecodeAdmin)
xadmin.site.register(Banner,BannerAdmin)
xadmin.site.register(views.BaseAdminView,BaseSetting)
xadmin.site.register(views.CommAdminView,GlobalSettings)