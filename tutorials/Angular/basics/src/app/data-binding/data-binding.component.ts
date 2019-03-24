import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-data-binding',
  templateUrl: './data-binding.component.html',
  styleUrls: ['./data-binding.component.css']
})
export class DataBindingComponent implements OnInit {

  buttonDisabled = false;

  inputData = '';

  buttonStatus = 'Button not clicked';

  name = 'Gyanesh';
  dummy = ' Interpolation ';

  constructor() {
    setTimeout(() => {
      this.buttonDisabled = true;
    }, 2000);
  }

  ngOnInit() {
  }

  sendDummy() {
    return 'Done';
  }

  onButtonClicked() {
    this.buttonStatus = 'Button Clicked';
  }

  onInputChange(event: any) {
    this.inputData = event.target.value;
    // If IDE Don't recognize the value then use explicit type casting
    this.inputData = (event.target as HTMLInputElement).value;
  }
}
