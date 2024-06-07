from django.shortcuts import render, redirect
from django.contrib import messages
from .forms import ContentForm
from .models import Content

# Create your views here.
def index(request):
    if request.method == "POST": #2 요청이 POST 형식일 때
        form = ContentForm(request.POST)
        if form.is_valid():
            content_form = form.save(commit=False) # 바로 저장하는 것을 방지
            content_form.save()
            return redirect('result/')
        else:
            messages.error(request, "error")
            return redirect('main/index.html')

    else: #1 index.html 페이지에 접속하면 여기가 먼저 실행된다.
        form = ContentForm()
        context = {
            'form': form
        }
        return render(request, 'main/index.html', context)


def result(request):
    result_list = Content.objects.all()
    context = {
        'result_list' : result_list
    }
    return render(request, 'main/result.html', context)