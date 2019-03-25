import { Component, OnInit } from '@angular/core';
import { LoggingService } from '../services/logging.service';

// Providers tells the angular which service the component require and it will get it for you
@Component({
  selector: 'app-logging-service-example',
  templateUrl: './app-logging-service-example.component.html',
  styleUrls: ['./app-logging-service-example.component.css'],
  providers: [LoggingService]
})
export class AppLoggingServiceExampleComponent implements OnInit {

  constructor(private loggingService: LoggingService) { }

  ngOnInit() {
  }

  buttonClicked() {
    this.loggingService.logToConsole('Button Clicked');
  }

}
