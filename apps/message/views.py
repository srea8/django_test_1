# _*_ coding:utf-8 _*_
from django.shortcuts import render
from .models import UserMessage
import MySQLdb

# Create your views here.

def getform(request):
    # all_messages=UserMessage.objects.all()
    # name_messages = UserMessage.objects.filter(name='bobby',address=u'北京')#过滤器
    # for message in all_messages:
    #     print(message.email)
    #
    # user_message = UserMessage()
    # user_message.name='bobby'
    # user_message.message='hello,world'
    # user_message.address='上海'
    # user_message.email='2@2.com'
    # user_message.object_id='2'
    # user_message.save()

    if request.method == "POST":
        name = request.POST.get('name','')
        messgae = request.POST.get('address','')
        email = request.POST.get('email','')
        user_message = UserMessage()
        user_message.name=name
        user_message.message=messgae
        user_message.address='上海'
        user_message.email=email
        user_message.object_id='2'
        user_message.save()
        user_message.delete()
    return render(request,'login.html')

