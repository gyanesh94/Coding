import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'basics';

  childText = 'child property binded';
  childAlias = 'child alias property binded';

  eventEmittedText: string;

  buttonClickedInChild(data: string) {
    this.eventEmittedText = data;
  }
}
