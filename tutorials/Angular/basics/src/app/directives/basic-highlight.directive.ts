import { Directive, ElementRef, OnInit } from '@angular/core';

@Directive({
  selector: '[appBasicHighlight]'
})
export class BasicHighlightDirective implements OnInit {
  // this is not a good practice of using element reference to access
    // as angular might change or delete it any time.
    // angular not only with browser it also works with serviceWorker in which DOM is not created
    // to check out better one go to better-highlight-directive.ts
  constructor(private elementRef: ElementRef) { }

  ngOnInit() {
    this.elementRef.nativeElement.style.backgroundColor = 'green';
  }

}
