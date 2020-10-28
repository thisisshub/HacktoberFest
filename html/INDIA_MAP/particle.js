<script>// Set bounce animation speed
var bounceSpeed = 7;

/* Ball Bouncing On Text © Yogev Ahuvia
 * ===========================================
 * This bouncing ball jumps over the words
 * inside the contentEditable paragraph.
 * The text itself is editable, the jump speed
 * is dynamic, and the ball bounce animation 
 * duration is set by the length of each word.
 *
 * Have you tried switching off the light? :)
 * -------------------------------------------
 * Works best on Google Chrome.
 */

var Bouncer = function(elem) {
  // init bouncable element and helpers
  this.$elem = $(elem);
  this.$ball = $('<div class="ball"></div>');
  this.$space = $('<span>&nbsp;</span>');
  this.timers = [];
  
  // handle in-place editing events
  this.$elem.on('blur', (function(instance) {
    return function() {
      instance.init();
      instance.bounce();
    };
  })(this));
  
  this.$elem.on('keypress', function(e) {
    var code = (e.keyCode ? e.keyCode : e.which);
    if (code == 13) {
      $(this).blur();
    }
  });
  
  // make it bounce
  this.init();
  this.bounce();
};

Bouncer.prototype.init = function() {
  // get element text for parsing
  this.elemText = this.$elem.text();
  
  // clone element for new text injection
  this.$cloned = this.$elem.clone()
                           .empty()
                           .addClass('cloned')
                           .removeAttr('contenteditable')
                           .appendTo(this.$elem.parent());
  
  // handle cloned element termination
  this.$cloned.on('click', (function(instance) {
    return function() {
      instance.reset();
      instance.$elem.focus();
      document.execCommand('selectAll', false, null);
    };
  })(this));
  
  this.$elem.hide(); // hide original element while animating
  this.$ball.appendTo(this.$cloned); // add ball to new element
  this.contentArray = this.elemText.split(' ');
};

Bouncer.prototype.bounce = function() {
  // ball animation incrementing delay
  var incrementingDelay = 0;
  
  // run through the text
  for (var j = 0; j < this.contentArray.length; j++) {
    var word = this.contentArray[j];
    
    // handle multiple spaces
    if (/\s/g.test(word)) {
      this.$space.clone().appendTo(this.$cloned);
      this.contentArray.splice(j, 1);
      j--;
      continue;
    }
    
    // escape each word with a span, add it to cloned element
    var $word = $('<span class="word">' + word + '</span>');
    this.$cloned.append($word);
    var wordLength = $word.width();
    
    // add white space elements between words
    if (j+1 < this.contentArray.length) {
      this.$space.clone().appendTo(this.$cloned);
    }
    
    // get ball position above word
    var ballLeft = $word[0].offsetLeft + wordLength/2;
    var ballTop = $word[0].offsetTop;
    
    var ballProps = {left: ballLeft,
                     top: ballTop,
                     wordLength: wordLength,
                     wordIndex: j};
    
    // preset timers for the whole text
    var timer = setTimeout((function(instance, ballProps) {
      return function() {
        instance.animateBall(ballProps);
      };
    })(this, ballProps), incrementingDelay);
    this.timers.push(timer);
    
    incrementingDelay += wordLength * bounceSpeed;
  }
  
  // hide ball when finished bouncing
  var timer = setTimeout((function(instance) {
    return function() {
      instance.$ball.fadeOut();
    };
  })(this), incrementingDelay);
  this.timers.push(timer);
}

Bouncer.prototype.animateBall = function(ballProps) {
  
  // set ball transition duration per word length
  var leftDuration = ballProps.wordLength * bounceSpeed + 'ms';
  var topDuration = (ballProps.wordLength * bounceSpeed / 2) + 'ms';
  this.$ball.css('transition-duration', 
                 leftDuration + ', ' + topDuration);
  
  // animate ball halfway and up
  var ballOffsetLeft = this.$ball[0].offsetLeft;
  var delta = ballProps.left - ballOffsetLeft;
  var ballHalfWay = ballOffsetLeft + delta;
  this.$ball.css({'left': ballHalfWay + 'px', 
                  'top': '-50px'});
  
  // finish animation when the ball reach halfway
  var halfwayReached = ballProps.wordLength * bounceSpeed / 2;
  var timer = setTimeout((function(instance, ballProps) {
    return function() {
      
      // animate ball to finish the bounce
      instance.$ball.css({'left': ballProps.left + 'px' , 
                          'top': '0px'});
      
      // light the bounced word when the ball bounces on it
      var bouncedOnWord = ballProps.wordLength * bounceSpeed / 2;
      var timer = setTimeout((function(instance, ballProps) {
        return function() {
          instance.$cloned
                  .find('.word')
                  .eq(ballProps.wordIndex)
                  .addClass('lit');
        };
      })(instance, ballProps), bouncedOnWord);
      instance.timers.push(timer);
    };
  })(this, ballProps), halfwayReached);
  this.timers.push(timer);
}

Bouncer.prototype.reset = function() {
  for (var i = 0; i < this.timers.length; i++) {
    clearTimeout(this.timers[i]);
  }
  this.timers.length = 0;
  
  this.$elem.show();
  this.$cloned.remove();
  this.$ball.removeAttr('style');
}

var bouncers = [];
$(document).ready(function() {
  // make all 'bouncer' classes, bounce
  $('.bouncer').each(function(index, element) {
    bouncers.push(new Bouncer(element));
  });;
  
  // handle light switch
  $('.light-switch').on('click', function() {
    $('body').toggleClass('dark');
    
    for (var i = 0; i < bouncers.length; i++) {
      bouncers[i].reset();
      bouncers[i].init();
      bouncers[i].bounce();
    }
  });
  
  // show hint
  $('.hint').removeClass('preload');
  setTimeout(function() {
    $('.hint').addClass('open');
    setTimeout(function() {
      $('.hint').removeClass('open');
    }, 4000);
  }, 6000);
});</script>