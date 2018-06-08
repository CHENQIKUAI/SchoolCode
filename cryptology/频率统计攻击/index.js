$('.encrypt').click(function () {
    var c = $('#m').val();
    var arr = [];

    for (var i = 0; i < c.length; ++i) {
        var mark = 0;
        for (var j = 0; j < arr.length; ++j) {
            if (arr[j][0] == c[i]) {
                arr[j][1]++;
                mark = 1;
                break;
            }
        }
        if (!mark) {
            arr.push([c[i], 1]);
        }
    }
    arr.sort(function (x, y) {
        return y[1] - x[1];
    });


    var str_sort = '';

    for (var i = 0; i < arr.length; ++i) {
        arr[i][1] = arr[i][1] * 100 / c.length;
        str_sort = str_sort + arr[i][0] + ' ' + arr[i][1].toFixed(1) + '%   ';
    }


    console.log(str_sort);
    $("#mm").val(c);



    var $p = $('.show-array');
    $p.html(str_sort);



});

$('#btn-change').click(() => {
    var a = $('#input-changeA:text').val();
    var b = $('#input-changeB:text').val();
    var buttom = $('#mm').val();
    var temp = '';
    for (var i = 0; i < buttom.length; ++i) {
        if (buttom[i] == a) {
            temp += b;
        } else {
            temp += buttom[i];
        }
    }
    console.log(temp);
    $("#mm").val(temp);
})




function copy(txt) {
    var oInput = document.createElement('input');
    oInput.value = txt;
    document.body.appendChild(oInput);
    oInput.select(); // 选择对象
    document.execCommand("Copy"); // 执行浏览器复制命令
    oInput.className = 'oInput';
    oInput.style.display = 'none';
    alert('复制成功');
}


$('.copy1').click(function () {
    var txt = $('#m').val();
    copy(txt);
});


$('.copy2').click(function () {
    var txt = $('#mm').val();
    copy(txt);
});


function jsReadFiles(files) {
    if (files.length) {
        var file = files[0];
        var reader = new FileReader(); //new一个FileReader实例
        if (/text+/.test(file.type)) { //判断文件类型，是不是text类型
            reader.onload = function () {
                $('#m').val(this.result);
            }
            reader.readAsText(file);
            $(this).val("");
        }
    }
}

function jsReadFiles2(files) {
    if (files.length) {
        var file = files[0];
        var reader = new FileReader(); //new一个FileReader实例
        if (/text+/.test(file.type)) { //判断文件类型，是不是text类型
            reader.onload = function () {
                $('#mm').val(this.result);
            }
            reader.readAsText(file);
        }
    }
}