# _*_ coding:utf-8 _*_

from django import forms

class LoginForm(forms.Form):
    username = forms.CharField(required=True,error_messages={'required':'用户名不能为空'})
    password = forms.CharField(required=True,min_length=8)