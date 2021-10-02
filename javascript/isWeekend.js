function isWeekend(){
  let  myDate = new Date();
  myDate.setFullYear(2009);
  myDate.setMonth(7);
  myDate.setDate(25);
  return myDate.getDay() == 6 || myDate.getDay() == 0
}
