import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-custom-structural-directive-example',
  templateUrl: './custom-structural-directive-example.component.html',
  styleUrls: ['./custom-structural-directive-example.component.css']
})
export class CustomStructuralDirectiveExampleComponent implements OnInit {
  flag: boolean;

  constructor() { }

  ngOnInit() {
  }

  changeBooleanValue() {
    this.flag = !this.flag;
  }

}
