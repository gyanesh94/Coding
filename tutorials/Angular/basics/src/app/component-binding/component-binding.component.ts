import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-component-binding',
  templateUrl: './component-binding.component.html',
  styleUrls: ['./component-binding.component.css']
})
export class ComponentBindingComponent implements OnInit {
  // @Input its a decorator definig the given property is accessible outside the component
  @Input() childProperty: string;

  // To give alias to the child element add string in Input argument.
  // why bad practice
    // - Two names for the same property (one private, one public) is inherently confusing.
    // - You should use an alias when the directive name is also an input property, and the directive name doesn't describe the property.
  // tslint:disable-next-line: no-input-rename
  @Input('childAlias') childPropertyAlias: string;

  @Input() eventEmittion: boolean;

  // @Output is used to send events from child to parent.
    // Output as child component is sending out
  // EventEmitter is module used to send events
    // <T> is generic and can send any data types.
  @Output() buttonClicked = new EventEmitter<string>();

  constructor() { }

  ngOnInit() {
  }

  emitEvent() {
    this.buttonClicked.emit('Button Clicked');
  }

}
