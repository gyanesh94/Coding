import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { SelectorClassComponent } from './selector-class.component';

describe('SelectorClassComponent', () => {
  let component: SelectorClassComponent;
  let fixture: ComponentFixture<SelectorClassComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ SelectorClassComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(SelectorClassComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
