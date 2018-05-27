var weather;
var address = "杭州";
$.ajax({
    type: "GET", //提交方式  
    url: "https://free-api.heweather.com/s6/weather/forecast?", //路径  
    data: {
        "location": address,
        "key": 'ddd2b59bf69743c092d4f43d9db570bb',
    }, //数据，这里使用的是Json格式进行传输
    dataType: 'json',
    success: function(result) { //返回数据根据结果进行相应的处理  
        console.log(result);
        weather = result.HeWeather6[0];
        if (result.HeWeather6[0].status == 'ok') {
            console.log("success");
            $('.location').text(weather.basic.location);

            $('.day1 > .date').text(weather.daily_forecast[0].date);

            $('.day1 > .wind_dir').text(weather.daily_forecast[0].wind_dir);

            $('.day1 > .tmp_max').text(weather.daily_forecast[0].tmp_max);

            $('.day1 > .tmp_min').text(weather.daily_forecast[0].tmp_min);

            $('.day1 > .cond_txt_d').text(weather.daily_forecast[0].cond_txt_d);

            $('.day2 > .date').text(weather.daily_forecast[1].date);

            $('.day2 > .wind_dir').text(weather.daily_forecast[1].wind_dir);

            $('.day2 > .tmp_max').text(weather.daily_forecast[1].tmp_max);

            $('.day2 > .tmp_min').text(weather.daily_forecast[1].tmp_min);

            $('.day2 > .cond_txt_d').text(weather.daily_forecast[1].cond_txt_d);

            $('.day3 > .date').text(weather.daily_forecast[2].date);

            $('.day3 > .wind_dir').text(weather.daily_forecast[2].wind_dir);

            $('.day3 > .tmp_max').text(weather.daily_forecast[2].tmp_max);

            $('.day3 > .tmp_min').text(weather.daily_forecast[2].tmp_min);

            $('.day3 > .cond_txt_d').text(weather.daily_forecast[2].cond_txt_d);
        } else {
            console.log("not success");
        }
    }
});


$("#select").change(function(){
    address = $('#select').find("option:selected").text();
    $.ajax({
    type: "GET", //提交方式  
    url: "https://free-api.heweather.com/s6/weather/forecast?", //路径  
    data: {
        "location": address,
        "key": 'ddd2b59bf69743c092d4f43d9db570bb',
    }, //数据，这里使用的是Json格式进行传输
    dataType: 'json',
    success: function(result) { //返回数据根据结果进行相应的处理  
        console.log(result);
        weather = result.HeWeather6[0];
        if (result.HeWeather6[0].status == 'ok') {
            console.log("success");
            $('.location').text(weather.basic.location);

            $('.day1 > .date').text(weather.daily_forecast[0].date);

            $('.day1 > .wind_dir').text(weather.daily_forecast[0].wind_dir);

            $('.day1 > .tmp_max').text(weather.daily_forecast[0].tmp_max);

            $('.day1 > .tmp_min').text(weather.daily_forecast[0].tmp_min);

            $('.day1 > .cond_txt_d').text(weather.daily_forecast[0].cond_txt_d);

            $('.day2 > .date').text(weather.daily_forecast[1].date);

            $('.day2 > .wind_dir').text(weather.daily_forecast[1].wind_dir);

            $('.day2 > .tmp_max').text(weather.daily_forecast[1].tmp_max);

            $('.day2 > .tmp_min').text(weather.daily_forecast[1].tmp_min);

            $('.day2 > .cond_txt_d').text(weather.daily_forecast[1].cond_txt_d);

            $('.day3 > .date').text(weather.daily_forecast[2].date);

            $('.day3 > .wind_dir').text(weather.daily_forecast[2].wind_dir);

            $('.day3 > .tmp_max').text(weather.daily_forecast[2].tmp_max);

            $('.day3 > .tmp_min').text(weather.daily_forecast[2].tmp_min);

            $('.day3 > .cond_txt_d').text(weather.daily_forecast[2].cond_txt_d);
        } else {
            console.log("not success");
            console.log(address)
        }
        // console.log(a.status);
    }
});
})