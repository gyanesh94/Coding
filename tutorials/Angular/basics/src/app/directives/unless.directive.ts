import { Directive, Input, TemplateRef, ViewContainerRef } from '@angular/core';

@Directive({
  selector: '[appUnless]'
})
export class UnlessDirective {
  // unless is still a property
    // setter is just method of the property which is called whenever unless value change
    // property should share the name of the selector
  @Input() set appUnless(condition: boolean) {
    if (!condition) {
      this.vcRef.createEmbeddedView(this.templateRef);
    } else {
      this.vcRef.clear();
    }
  }

  // templateRef reference to ng-template in which structural directive will be kept
  // vcRef reference to the view container in which template will be rendered
  constructor(private templateRef: TemplateRef<any>, private vcRef: ViewContainerRef) { }

}
