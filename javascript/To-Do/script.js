const input = document.querySelector("#add"); //text box
const  btn = document.querySelector("#bttn"); // Add button
const list = document.querySelector("#item"); // li item
var element = document.getElementsByTagName('li'); 



//function to add todo
btn.onclick = function(){

    var txt = input.value;
    if(txt ==''){
        alert('Add some text');
    }else{
        li = document.createElement('li');
        li.classList.add("task");
        li.innerHTML = `<button id="edt" class="edit"><i class="fas fa-pencil-alt"></i></button>${txt}<button id="dlt" class="delete">X</button>`;
        list.insertBefore(li,list.childNodes[0]);
        input.value = '';
      addDeleteEvents();
      
    }
    editTodo();
    
};
//function to mark todo as done (strikethrough)
list.onclick = function(ev){
    if(ev.target.tagName == 'LI'){
         ev.target.classList.toggle('checked');
    }
}

// function to delete todo
function addDeleteEvents(){
  var tasks = document.querySelectorAll(".task");
   for (var index = 0; index <tasks.length; index++){
        tasks[index].addEventListener("click", function(){
         this.classList.toggle("active");
      });
      tasks[index].querySelector("#dlt").addEventListener("click",
      function(){
         this.closest(".task").remove();
      });
    

   }
}

addDeleteEvents();

//function to add odo on enter key press
document.getElementById("add")
    .addEventListener("keyup", function(event) {
    event.preventDefault();
    if (event.keyCode === 13) {
        document.getElementById("bttn").click();
    }
});


//function to edit todo
function editTodo(){
    const edit = document.getElementsByClassName('edit');
    for (var index = 0; index <edit.length; index++){
      edit[index].addEventListener("click",
        function(){
        var text = prompt("Edit This To-Do ");
        this.closest(".task").innerHTML = `<button id="edt" class="edit"><i class="fas fa-pencil-alt"></i></button>${text}<button id="dlt"    class="delete">X</button>`;
        addDeleteEvents();
    }
      )
   }
   
  }
  editTodo();