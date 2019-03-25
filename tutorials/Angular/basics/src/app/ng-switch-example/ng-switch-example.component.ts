import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-ng-switch-example',
  templateUrl: './ng-switch-example.component.html',
  styleUrls: ['./ng-switch-example.component.css']
})
export class NgSwitchExampleComponent implements OnInit {
  inputValue = 3;

  constructor() { }

  ngOnInit() {
  }

  changeValue() {
    this.inputValue = Math.floor(Math.random() * 10);
  }

}
