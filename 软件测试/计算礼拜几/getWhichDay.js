//判断是否是闰年
const isLeapYear = (year) => {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}


//从某年开始到某年里面的天数
const getDaysByYearMod7 = (yearEnd) => {
	const yearStart = 1;
	let days = 0;
	for (var i = yearStart; i < yearEnd; ++i) {
		if (isLeapYear(i)) {
			days += 366;
		} else {
			days += 365;
		}
		days %= 7;
	}
	return days;
}


//从年初到某天的天数
const getDaysFromYearBeginMod7 = (year, month, day) => {

	let days = 0;
	let monthList = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
	//如果是闰年修改2月天数
	if (isLeapYear(year)) {
		monthList[1] = 29;
	}

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > monthList[month - 1]) {
		return;
	}

	for (var i = 1; i < month; ++i) {
		days += monthList[i - 1];
		days %= 7;
	}

	days += day;
	days--;
	days %= 7;
	return days;
}

const getWhichDay = (year, month, day) => {
	const list = ['礼拜一', '礼拜二', '礼拜三', '礼拜四', '礼拜五', '礼拜六', '礼拜七'];

	let days1 = getDaysByYearMod7(year);
	let days2 = getDaysFromYearBeginMod7(year, month, day);

	if (typeof year != 'number' || typeof month != 'number' || typeof day != 'number') {
		console.log("please input date with numbers");
	} else if (days2 == undefined) {
		console.log('invalue date')
	} else {
		let gap = (days1 + days2) % 7;
		console.log(list[gap]);
	}
}

getWhichDay(2019, 1, 1);