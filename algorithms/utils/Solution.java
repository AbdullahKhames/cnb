class Solution {
    private static final int[] numberDaysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final int totalYearDays = 365;
    private static final int totalYearMonths = 12;
    public int daysBetweenDates(String date1, String date2) {
        String []date1Arr = date1.split("-");
        String []date2Arr = date2.split("-");
        int totalDays = 0;

        int startYear = Integer.parseInt(date1Arr[0]);
        int startMonth = Integer.parseInt(date1Arr[1]);
        int startDay = Integer.parseInt(date1Arr[2]);
        int endYear = Integer.parseInt(date2Arr[0]);
        int endMonth = Integer.parseInt(date2Arr[1]);
        int endDay = Integer.parseInt(date2Arr[2]);

        if (startYear > endYear) {
            int tempYear = startYear;
            startYear = endYear;
            endYear = tempYear;

            int tempMonth = startMonth;
            startMonth = endMonth;
            endMonth = tempMonth;

            int tempDay = startDay;
            startDay = endDay;
            endDay = tempDay;
        } else if (startYear == endYear) {
            if (startMonth > endMonth) {
                int tempMonth = startMonth;
                startMonth = endMonth;
                endMonth = tempMonth;
    
                int tempDay = startDay;
                startDay = endDay;
                endDay = tempDay;
            }else if (startMonth == endMonth) {
                if (startDay > endDay) {
                    int tempDay = startDay;
                    startDay = endDay;
                    endDay = tempDay;
                }
            }
        }
        for(int i = startYear; i <= endYear; i++) {
            if (i == startYear || i == endYear) {
                totalDays += daysBetweenDates(i, startYear, startMonth, startDay, endYear, endMonth, endDay);
            } 
            else {
                totalDays += getFullYearDays(i);
            }
        }
        return totalDays;
    }

    private int daysBetweenDates(int currentYear ,int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay) {
        int totalDays = 0;
        boolean hasFerbruary = false;
        if (startYear == endYear) {
            //get days difference in same year
            if (startMonth == 2 && startDay < 29) {
                hasFerbruary = true;
            }
            else if (startMonth < 3) {
                hasFerbruary = true;
            }
            if (startMonth == endMonth) {
                totalDays += endDay - startDay;
            }else {
                int startMonthDays = numberDaysPerMonth[startMonth - 1] - startDay;
                totalDays += startMonthDays;
                totalDays += endDay;
                for (int i = startMonth + 1; i <= endMonth - 1; i++) {
                    totalDays += numberDaysPerMonth[i - 1];
                }
            }
        } else if (currentYear == startYear) {
            // get days differnce from the startMonth and start day till the end of the year 
            if (startMonth == 2 && startDay < 29) {
                hasFerbruary = true;
            }
            else if (startMonth < 3) {
                hasFerbruary = true;
            }
            // count from this day to the end of year
            int startMonthDays = numberDaysPerMonth[startMonth - 1] - startDay;
            totalDays += startMonthDays;
            for (int i = startMonth + 1; i <= totalYearMonths; i++) {
                totalDays += numberDaysPerMonth[i - 1];
            }
        } else if (currentYear == endYear) {
            // get days differnce from the year start till the endMonth and end day
            if (endMonth == 2) {
                if (endDay == 29) {
                    hasFerbruary = true;
                }
            } else if (endMonth > 1) {
                hasFerbruary = true;
            }
            //count of days from start of year till that given day
            totalDays += endDay;
            for (int i = 1; i <= endMonth - 1; i++) {
                totalDays += numberDaysPerMonth[i - 1];
            }
        }
        //check if currrent year is leap and counting passes through february if so add 1 to the number
        if (isLeap(currentYear) && hasFerbruary) {
            totalDays += 1;
        }
        return totalDays;
    }

    private int getFullYearDays(int year) {
        if (isLeap(year)) {
            return totalYearDays + 1;
        }
        return totalYearDays;
    }
    private boolean isLeap(int year) {
        return year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0);
    }
    public static void main(String []arrgs) {
        Solution solution = new Solution();
        System.out.println(solution.daysBetweenDates("2023-01-13", "2044-02-11"));;
    }
}
