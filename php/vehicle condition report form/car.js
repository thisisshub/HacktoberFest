let class_extractor = /damage_report\[([a-zA-Z]+)\]/

function fillCarReport() {
  let $formData = $('#form').serializeArray();
  $formData.forEach(element => {
    console.log(element);
    let c = class_extractor.exec(element.name)[1];
    $(`svg #layer102 > g > *[data-part=${element.value}]`).removeClass();
    $(`svg #layer102 > g > *[data-part=${element.value}]`).addClass(c);
  });
}

$(document).ready(function() {
  $('svg').bind("contextmenu", function (event) {
    event.preventDefault();
  });
  
  $(document).bind("mousedown", function (e) {
    if (!$(e.target).parents(".custom-menu").length > 0) {
      $(".custom-menu").hide(100);
    }
  });
  
  $(".custom-menu li").click(function () {
    let $clickedPart = window.clickedPart;
    $($clickedPart).removeClass();
    $($clickedPart).addClass($(this).attr("data-action"));
    $("#form").append( `<input name="damage_report[${$(this).attr("data-action")}][]" value="${$($clickedPart).attr("data-part")}" />`);
    $(".custom-menu").hide(100);
    window.clickedPart = null;
  });
  
  $('svg #layer102 > g > *').click(function () {
    window.clickedPart = this;
    $(".custom-menu")
      .finish()
      .toggle(100)
      .css({
        top: event.pageY + "px",
        left: event.pageX + "px"
      });
  });

  fillCarReport();
})