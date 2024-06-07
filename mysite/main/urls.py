from django.urls import path

from . import views


urlpatterns = [
    path('', views.index, name='index'),   # 첫 번째 인자: 사용자가 들어오는 경로, 두 번째 인자: 해당 경로로 들어왔을 때 실행되는 함수 
    path('result/', views.result, name='result'),
]
