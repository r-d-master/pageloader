(function() {
  window.onload = function() {
    var pagewrap = document.getElementById("page-wrapper");
    var pages = [].slice.call(pagewrap.querySelectorAll('#page'));
    var currentPage = 0;
    var triggerLoading = [].slice.call(pagewrap.querySelectorAll('a'));
    var loader = new SVGLoader(document.getElementById('loader'), { speedIn : 100 });

    function init() {
      triggerLoading.forEach( function(trigger) {
        trigger.addEventListener('click', function(ev) {
          ev.preventDefault();
          loader.show();
          // after some time hide loader
          setTimeout( function() {
            loader.hide();

            classie.removeClass(pages[currentPage], 'show');
            // update..
            // currentPage = currentPage ? 0 : 1;
            classie.addClass(pages[currentPage], 'show');
          }, 20000 );
        } );
      } );
    }

    init();
  }
})();
